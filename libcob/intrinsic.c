/*
   Copyright (C) 2005-2012 Roger While

   This file is part of GNU Cobol.

   The GNU Cobol runtime library is free software: you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GNU Cobol is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with GNU Cobol.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#ifdef	HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#include <math.h>

/* Note we include the Cygwin version of windows.h here */
#if defined(_WIN32) || defined(__CYGWIN__)
#undef	HAVE_LANGINFO_CODESET
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#ifdef	_WIN32
#include <sys/timeb.h>
#endif
#endif

#ifdef	HAVE_LANGINFO_CODESET
#include <langinfo.h>
#endif

#ifdef	HAVE_LOCALE_H
#include <locale.h>
#endif

/* Force symbol exports */
#define	COB_LIB_EXPIMP

#include "libcob.h"
#include "coblocal.h"

/* Local variables */

static cob_global	*cobglobptr;

static const cob_field_attr	const_alpha_attr =
				{COB_TYPE_ALPHANUMERIC, 0, 0, 0, NULL};

/* Working fields */
static cob_field	*move_field;

static cob_decimal	d1;
static cob_decimal	d2;
static cob_decimal	d3;
static cob_decimal	d4;
static cob_decimal	d5;

static mpz_t		cob_mexp;
static mpz_t		cob_mpzt;

static mpf_t		cob_mpft;
static mpf_t		cob_mpft2;
static mpf_t		cob_mpft_get;
static mpf_t		cob_log_half;
static mpf_t		cob_sqrt_two;
static mpf_t		cob_pi;


/* Stack definitions for created fields */

struct calc_struct {
	cob_field	calc_field;
	cob_field_attr	calc_attr;
	size_t		calc_size;
};

static struct calc_struct	*calc_base;
static cob_field		*curr_field;
static cob_u32_t		curr_entry;

/* Constants for date/day calculations */
static const int normal_days[] =
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
static const int leap_days[] =
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
static const int normal_month_days[] =
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const int leap_month_days[] =
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* Locale name to Locale ID table */
#if defined(_WIN32) || defined(__CYGWIN__)

struct winlocale {
	const char	*winlocalename;
	const int	winlocaleid;
};

static const struct winlocale	wintable[] =
{
	{ "af_ZA",		0x0436 },
	{ "am_ET",		0x045e },
	{ "ar_AE",		0x3801 },
	{ "ar_BH",		0x3c01 },
	{ "ar_DZ",		0x1401 },
	{ "ar_EG",		0x0c01 },
	{ "ar_IQ",		0x0801 },
	{ "ar_JO",		0x2c01 },
	{ "ar_KW",		0x3401 },
	{ "ar_LB",		0x3001 },
	{ "ar_LY",		0x1001 },
	{ "ar_MA",		0x1801 },
	{ "ar_OM",		0x2001 },
	{ "ar_QA",		0x4001 },
	{ "ar_SA",		0x0401 },
	{ "ar_SY",		0x2801 },
	{ "ar_TN",		0x1c01 },
	{ "ar_YE",		0x2401 },
	{ "arn_CL",		0x047a },
	{ "as_IN",		0x044d },
	{ "az_Cyrl_AZ",		0x082c },
	{ "az_Latn_AZ",		0x042c },
	{ "ba_RU",		0x046d },
	{ "be_BY",		0x0423 },
	{ "bg_BG",		0x0402 },
	{ "bn_IN",		0x0445 },
	{ "bo_BT",		0x0851 },
	{ "bo_CN",		0x0451 },
	{ "br_FR",		0x047e },
	{ "bs_Cyrl_BA",		0x201a },
	{ "bs_Latn_BA",		0x141a },
	{ "ca_ES",		0x0403 },
	{ "cs_CZ",		0x0405 },
	{ "cy_GB",		0x0452 },
	{ "da_DK",		0x0406 },
	{ "de_AT",		0x0c07 },
	{ "de_CH",		0x0807 },
	{ "de_DE",		0x0407 },
	{ "de_LI",		0x1407 },
	{ "de_LU",		0x1007 },
	{ "dsb_DE",		0x082e },
	{ "dv_MV",		0x0465 },
	{ "el_GR",		0x0408 },
	{ "en_029",		0x2409 },
	{ "en_AU",		0x0c09 },
	{ "en_BZ",		0x2809 },
	{ "en_CA",		0x1009 },
	{ "en_GB",		0x0809 },
	{ "en_IE",		0x1809 },
	{ "en_IN",		0x4009 },
	{ "en_JM",		0x2009 },
	{ "en_MY",		0x4409 },
	{ "en_NZ",		0x1409 },
	{ "en_PH",		0x3409 },
	{ "en_SG",		0x4809 },
	{ "en_TT",		0x2c09 },
	{ "en_US",		0x0409 },
	{ "en_ZA",		0x1c09 },
	{ "en_ZW",		0x3009 },
	{ "es_AR",		0x2c0a },
	{ "es_BO",		0x400a },
	{ "es_CL",		0x340a },
	{ "es_CO",		0x240a },
	{ "es_CR",		0x140a },
	{ "es_DO",		0x1c0a },
	{ "es_EC",		0x300a },
	{ "es_ES",		0x040a },
	{ "es_GT",		0x100a },
	{ "es_HN",		0x480a },
	{ "es_MX",		0x080a },
	{ "es_NI",		0x4c0a },
	{ "es_PA",		0x180a },
	{ "es_PE",		0x280a },
	{ "es_PR",		0x500a },
	{ "es_PY",		0x3c0a },
	{ "es_SV",		0x440a },
	{ "es_US",		0x540a },
	{ "es_UY",		0x380a },
	{ "es_VE",		0x200a },
	{ "et_EE",		0x0425 },
	{ "eu_ES",		0x042d },
	{ "fa_IR",		0x0429 },
	{ "fi_FI",		0x040b },
	{ "fil_PH",		0x0464 },
	{ "fo_FO",		0x0438 },
	{ "fr_BE",		0x080c },
	{ "fr_CA",		0x0c0c },
	{ "fr_CH",		0x100c },
	{ "fr_FR",		0x040c },
	{ "fr_LU",		0x140c },
	{ "fr_MC",		0x180c },
	{ "fy_NL",		0x0462 },
	{ "ga_IE",		0x083c },
	{ "gbz_AF",		0x048c },
	{ "gd",			0x043c },
	{ "gl_ES",		0x0456 },
	{ "gsw_FR",		0x0484 },
	{ "gu_IN",		0x0447 },
	{ "ha_Latn_NG",		0x0468 },
	{ "he_IL",		0x040d },
	{ "hi_IN",		0x0439 },
	{ "hr_BA",		0x101a },
	{ "hr_HR",		0x041a },
	{ "hu_HU",		0x040e },
	{ "hy_AM",		0x042b },
	{ "id_ID",		0x0421 },
	{ "ig_NG",		0x0470 },
	{ "ii_CN",		0x0478 },
	{ "is_IS",		0x040f },
	{ "it_CH",		0x0810 },
	{ "it_IT",		0x0410 },
	{ "iu_Cans_CA",		0x045d },
	{ "iu_Latn_CA",		0x085d },
	{ "ja_JP",		0x0411 },
	{ "ka_GE",		0x0437 },
	{ "kh_KH",		0x0453 },
	{ "kk_KZ",		0x043f },
	{ "kl_GL",		0x046f },
	{ "kn_IN",		0x044b },
	{ "ko_KR",		0x0412 },
	{ "kok_IN",		0x0457 },
	{ "ky_KG",		0x0440 },
	{ "lb_LU",		0x046e },
	{ "lo_LA",		0x0454 },
	{ "lt_LT",		0x0427 },
	{ "lv_LV",		0x0426 },
	{ "mi_NZ",		0x0481 },
	{ "mk_MK",		0x042f },
	{ "ml_IN",		0x044c },
	{ "mn_Cyrl_MN",		0x0450 },
	{ "mn_Mong_CN",		0x0850 },
	{ "moh_CA",		0x047c },
	{ "mr_IN",		0x044e },
	{ "ms_BN",		0x083e },
	{ "ms_MY",		0x043e },
	{ "mt_MT",		0x043a },
	{ "nb_NO",		0x0414 },
	{ "ne_NP",		0x0461 },
	{ "nl_BE",		0x0813 },
	{ "nl_NL",		0x0413 },
	{ "nn_NO",		0x0814 },
	{ "ns_ZA",		0x046c },
	{ "oc_FR",		0x0482 },
	{ "or_IN",		0x0448 },
	{ "pa_IN",		0x0446 },
	{ "pl_PL",		0x0415 },
	{ "ps_AF",		0x0463 },
	{ "pt_BR",		0x0416 },
	{ "pt_PT",		0x0816 },
	{ "qut_GT",		0x0486 },
	{ "quz_BO",		0x046b },
	{ "quz_EC",		0x086b },
	{ "quz_PE",		0x0c6b },
	{ "rm_CH",		0x0417 },
	{ "ro_MO",		0x0818 },
	{ "ro_RO",		0x0418 },
	{ "ru_MO",		0x0819 },
	{ "ru_RU",		0x0419 },
	{ "rw_RW",		0x0487 },
	{ "sa_IN",		0x044f },
	{ "sah_RU",		0x0485 },
	{ "se_FI",		0x0c3b },
	{ "se_NO",		0x043b },
	{ "se_SE",		0x083b },
	{ "si_LK",		0x045b },
	{ "sk_SK",		0x041b },
	{ "sl_SI",		0x0424 },
	{ "sma_NO",		0x183b },
	{ "sma_SE",		0x1c3b },
	{ "smj_NO",		0x103b },
	{ "smj_SE",		0x143b },
	{ "smn_FI",		0x243b },
	{ "sms_FI",		0x203b },
	{ "sq_AL",		0x041c },
	{ "sr_Cyrl_BA",		0x1c1a },
	{ "sr_Cyrl_CS",		0x0c1a },
	{ "sr_Latn_BA",		0x181a },
	{ "sr_Latn_CS",		0x081a },
	{ "st",			0x0430 },
	{ "sv_FI",		0x081d },
	{ "sv_SE",		0x041d },
	{ "sw_KE",		0x0441 },
	{ "syr_SY",		0x045a },
	{ "ta_IN",		0x0449 },
	{ "te_IN",		0x044a },
	{ "tg_Cyrl_TJ",		0x0428 },
	{ "th_TH",		0x041e },
	{ "tk_TM",		0x0442 },
	{ "tmz_Latn_DZ",	0x085f },
	{ "tn_ZA",		0x0432 },
	{ "tr_IN",		0x0820 },
	{ "tr_TR",		0x041f },
	{ "ts",			0x0431 },
	{ "tt_RU",		0x0444 },
	{ "ug_CN",		0x0480 },
	{ "uk_UA",		0x0422 },
	{ "ur_PK",		0x0420 },
	{ "uz_Cyrl_UZ",		0x0843 },
	{ "uz_Latn_UZ",		0x0443 },
	{ "vi_VN",		0x042a },
	{ "wen_DE",		0x042e },
	{ "wo_SN",		0x0488 },
	{ "xh_ZA",		0x0434 },
	{ "yi",			0x043d },
	{ "yo_NG",		0x046a },
	{ "zh_CN",		0x0804 },
	{ "zh_HK",		0x0c04 },
	{ "zh_MO",		0x1404 },
	{ "zh_SG",		0x1004 },
	{ "zh_TW",		0x0404 },
	{ "zu_ZA",		0x0435 }
};

#define	WINLOCSIZE	sizeof(wintable) / sizeof(struct winlocale)

#endif


/* Pi - Next 3 digits 000 */
static const char	cob_pi_str[] =
	"3.141592653589793238462643383279502884197169399375"
	"10582097494459230781640628620899862803482534211706"
	"79821480865132823066470938446095505822317253594081"
	"28481117450284102701938521105559644622948954930381"
	"96442881097566593344612847564823378678316527120190"
	"91456485669234603486104543266482133936072602491412"
	"73724587006606315588174881520920962829254091715364"
	"36789259036001133053054882046652138414695194151160"
	"94330572703657595919530921861173819326117931051185"
	"48074462379962749567351885752724891227938183011949"
	"12983367336244065664308602139494639522473719070217"
	"98609437027705392171762931767523846748184676694051"
	"32000568127145263560827785771342757789609173637178"
	"72146844090122495343014654958537105079227968925892"
	"35420199561121290219608640344181598136297747713099"
	"60518707211349999998372978049951059731732816096318"
	"59502445945534690830264252230825334468503526193118"
	"817101";
/* Sqrt 2 - Next 3 digits 001 */
static const char	cob_sqrt_two_str[] =
	"1.414213562373095048801688724209698078569671875376"
	"94807317667973799073247846210703885038753432764157"
	"27350138462309122970249248360558507372126441214970"
	"99935831413222665927505592755799950501152782060571"
	"47010955997160597027453459686201472851741864088919"
	"86095523292304843087143214508397626036279952514079"
	"89687253396546331808829640620615258352395054745750"
	"28775996172983557522033753185701135437460340849884"
	"71603868999706990048150305440277903164542478230684"
	"92936918621580578463111596668713013015618568987237"
	"23528850926486124949771542183342042856860601468247"
	"20771435854874155657069677653720226485447015858801"
	"62075847492265722600208558446652145839889394437092"
	"65918003113882464681570826301005948587040031864803"
	"42194897278290641045072636881313739855256117322040"
	"24509122770022694112757362728049573810896750401836"
	"98683684507257993647290607629969413804756548237289"
	"97180326802474420629269124859052181004459842150591"
	"12024944134172853147810580360337107730918286931471"
	"01711116839165817268894197587165821521282295184884"
	"72089694633862891562882765952635140542267653239694"
	"61751129160240871551013515045538128756005263146801"
	"71274026539694702403005174953188629256313851881634"
	"78";
/* Log 0.5 - Next 3 digits 000 */
static const char	cob_log_half_str[] =
	"-0.69314718055994530941723212145817656807550013436"
	"02552541206800094933936219696947156058633269964186"
	"87542001481020570685733685520235758130557032670751"
	"63507596193072757082837143519030703862389167347112"
	"33501153644979552391204751726815749320651555247341"
	"39525882950453007095326366642654104239157814952043"
	"74043038550080194417064167151864471283996817178454"
	"69570262716310645461502572074024816377733896385506"
	"95260668341137273873722928956493547025762652098859"
	"69320196505855476470330679365443254763274495125040"
	"60694381471046899465062201677204245245296126879465"
	"46193165174681392672504103802546259656869144192871"
	"60829380317271436778265487756648508567407764845146"
	"44399404614226031930967354025744460703080960850474"
	"86638523138181676751438667476647890881437141985494"
	"23151997354880375165861275352916610007105355824987"
	"94147295092931138971559982056543928717";

/* mpf_init2 length = ceil (log2 (10) * strlen (x)) */
#define	COB_PI_LEN		2820UL
#define	COB_SQRT_TWO_LEN	3827UL
#define	COB_LOG_HALF_LEN	2784UL

/* Local functions */

static void
make_field_entry (cob_field *f)
{
	unsigned char		*s;
	struct calc_struct	*calc_temp;

	calc_temp = calc_base + curr_entry;
	curr_field = &calc_temp->calc_field;
	if (f->size > calc_temp->calc_size) {
		if (curr_field->data) {
			free (curr_field->data);
		}
		calc_temp->calc_size = f->size + 1;
		s = cob_malloc (f->size + 1U);
	} else {
		s = curr_field->data;
		memset (s, 0, f->size);
	}

	*curr_field = *f;
	calc_temp->calc_attr = *(f->attr);
	curr_field->attr = &calc_temp->calc_attr;

	curr_field->data = s;

	if (++curr_entry >= COB_DEPTH_LEVEL) {
		curr_entry = 0;
	}
}

static int
leap_year (const int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0;
}

static int
comp_field (const void *m1, const void *m2)
{
	cob_field	*f1;
	cob_field	*f2;

	f1 = *(cob_field **) m1;
	f2 = *(cob_field **) m2;
	return cob_cmp (f1, f2);
}

/* Reference modification */
static void
calc_ref_mod (cob_field *f, const int offset, const int length)
{
	size_t		calcoff;
	size_t		size;

	if ((size_t)offset <= f->size) {
		calcoff = (size_t)offset - 1;
		size = f->size - calcoff;
		if (length > 0 && (size_t)length < size) {
			size = (size_t)length;
		}
		f->size = size;
		if (calcoff > 0) {
			memmove (f->data, f->data + calcoff, size);
		}
	}
}

/* Decimal <-> Decimal */

static COB_INLINE COB_A_INLINE void
cob_decimal_set (cob_decimal *dst, const cob_decimal *src)
{
	mpz_set (dst->value, src->value);
	dst->scale = src->scale;
}

/* Trim trailing zeros in decimal places */
static void
cob_trim_decimal (cob_decimal *d)
{
	if (!mpz_sgn (d->value)) {
		/* Value is zero */
		d->scale = 0;
		return;
	}
	for ( ; d->scale > 0; d->scale--) {
		if (!mpz_divisible_ui_p (d->value, 10UL)) {
			break;
		}
		mpz_tdiv_q_ui (d->value, d->value, 10UL);
	}
}

static void
cob_alloc_set_field_int (const int val)
{
	cob_u16_t	attrsign;
	cob_field_attr	attr;
	cob_field	field;

	if (val < 0) {
		attrsign = COB_FLAG_HAVE_SIGN;
	} else {
		attrsign = 0;
	}
	COB_ATTR_INIT (COB_TYPE_NUMERIC_BINARY, 9,
		       0, attrsign, NULL);
	COB_FIELD_INIT (4, NULL, &attr);
	make_field_entry (&field);
	memcpy (curr_field->data, &val, sizeof(int));
}

static void
cob_alloc_set_field_uint (const cob_u32_t val)
{
	cob_field_attr	attr;
	cob_field	field;

	COB_ATTR_INIT (COB_TYPE_NUMERIC_BINARY, 9,
		       0, 0, NULL);
	COB_FIELD_INIT (4, NULL, &attr);
	make_field_entry (&field);
	memcpy (curr_field->data, &val, sizeof(cob_u32_t));
}

static void
cob_alloc_field (cob_decimal *d)
{
	size_t		bitnum;
	size_t		sign;
	size_t		attrsign;
	int		size;
	int		scale;
	cob_field_attr	attr;
	cob_field	field;

	if (unlikely(d->scale == COB_DECIMAL_NAN)) {
		/* Check this */
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		COB_ATTR_INIT (COB_TYPE_NUMERIC_BINARY, 9,
			       0, 0, NULL);
		COB_FIELD_INIT (4, NULL, &attr);
		make_field_entry (&field);
		return;
	}

	if (mpz_sgn (d->value) < 0) {
		attrsign = COB_FLAG_HAVE_SIGN;
		sign = 1;
	} else {
		attrsign = 0;
		sign = 0;
	}

	cob_trim_decimal (d);

	bitnum = mpz_sizeinbase (d->value, 2);
	if (bitnum < (33 - sign) && d->scale < 10) {
		/* 4 bytes binary */
		COB_ATTR_INIT (COB_TYPE_NUMERIC_BINARY, 9,
			       d->scale, attrsign, NULL);
		COB_FIELD_INIT (4, NULL, &attr);
		make_field_entry (&field);
	} else if (bitnum < (65 - sign) && d->scale < 19) {
		/* 8 bytes binary */
		COB_ATTR_INIT (COB_TYPE_NUMERIC_BINARY, 20,
			       d->scale, attrsign, NULL);
		COB_FIELD_INIT (8, NULL, &attr);
		make_field_entry (&field);
	} else {
		/* Display decimal */
		size = (int)mpz_sizeinbase (d->value, 10);
		if (d->scale > size) {
			size = d->scale;
		}
		scale = d->scale;
		COB_ATTR_INIT (COB_TYPE_NUMERIC_DISPLAY, size,
			       scale, attrsign, NULL);
		COB_FIELD_INIT (size, NULL, &attr);
		make_field_entry (&field);
	}
}

/* Common function for intrinsics MOD and REM */

static cob_field *
cob_mod_or_rem (cob_field *f1, cob_field *f2, const int func_is_rem)
{
	int	sign;

	cob_set_exception (0);
	cob_decimal_set_field (&d2, f1);
	cob_decimal_set_field (&d3, f2);

	if (!mpz_sgn (d3.value)) {
		/* Divide by zero */
		cob_set_exception (COB_EC_SIZE_ZERO_DIVIDE);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	cob_decimal_div (&d2, &d3);

	/* Caclulate integer / integer-part */
	if (d2.scale < 0) {
		mpz_ui_pow_ui (cob_mexp, 10UL, (cob_uli_t)-d2.scale);
		mpz_mul (d2.value, d2.value, cob_mexp);
	} else if (d2.scale > 0) {
		sign = mpz_sgn (d2.value);
		mpz_ui_pow_ui (cob_mexp, 10UL, (cob_uli_t)d2.scale);
		if (func_is_rem) {
			/* REMAINDER function - INTEGER-PART */
			mpz_tdiv_q (d2.value, d2.value, cob_mexp);
		} else {
			/* MOD function - INTEGER */
			mpz_tdiv_qr (d2.value, cob_mpzt, d2.value, cob_mexp);
			/* Check negative and has decimal places */
			if (sign < 0 && mpz_sgn (cob_mpzt)) {
				mpz_sub_ui (d2.value, d2.value, 1UL);
			}
		}
	}
	d2.scale = 0;

	cob_decimal_set_field (&d1, f2);
	cob_decimal_mul (&d2, &d1);
	cob_decimal_set_field (&d1, f1);
	cob_decimal_sub (&d1, &d2);

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

/* Validate NUMVAL / NUMVAL-C item */
/* [spaces][+|-][spaces]{digits[.[digits]]|.digits}[spaces] */
/* [spaces]{digits[.[digits]]|.digits}[spaces][+|-|CR|DB][spaces] */

static int
cob_check_numval (const cob_field *srcfield, const cob_field *currency,
		  const int chkcurr, const int anycase)
{
	unsigned char	*p;
	unsigned char	*begp;
	unsigned char	*endp;
	size_t		pos;
	size_t		plus_minus;
	size_t		digits;
	size_t		dec_seen;
	size_t		space_seen;
	size_t		break_needed;
	size_t		currcy_size;
	int		n;
	unsigned char	dec_pt;
	unsigned char	cur_symb;

	begp = NULL;
	currcy_size = 0;
	if (currency) {
		endp = NULL;
		p = currency->data;
		for (pos = 0; pos < currency->size; pos++, p++) {
			switch (*p) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '+':
			case '-':
			case '.':
			case ',':
			case '*':
				return 1;
			case ' ':
				break;
			default:
				if (pos < currency->size - 1) {
					if (!memcmp (p, "CR", (size_t)2)) {
						return 1;
					}
					if (!memcmp (p, "DB", (size_t)2)) {
						return 1;
					}
				}
				if (!begp) {
					begp = p;
				}
				endp = p;
				break;
			}
		}
		if (!begp) {
			return 1;
		}
		currcy_size = endp - begp;
		currcy_size++;
		if (currcy_size >= srcfield->size) {
			begp = NULL;
			currcy_size = 0;
		}
	} else if (chkcurr) {
		cur_symb = COB_MODULE_PTR->currency_symbol;
		begp = &cur_symb;
		currcy_size = 1;
	}

	if (!srcfield->size) {
		return 1;
	}

	p = srcfield->data;
	plus_minus = 0;
	digits = 0;
	dec_seen = 0;
	space_seen = 0;
	break_needed = 0;
	dec_pt = COB_MODULE_PTR->decimal_point;

	/* Check leading positions */
	for (n = 0; n < (int)srcfield->size; ++n, ++p) {
		switch (*p) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			break_needed = 1;
			break;
		case ' ':
			continue;
		case '+':
		case '-':
			if (plus_minus) {
				return n + 1;
			}
			plus_minus = 1;
			continue;
		case ',':
		case '.':
			if (*p != dec_pt) {
				return n + 1;
			}
			break_needed = 1;
			break;
		default:
			if (begp && n < (int)(srcfield->size - currcy_size)) {
				if (!memcmp (p, begp, currcy_size)) {
					break;
				}
			}
			return n + 1;
		}
		if (break_needed) {
			break;
		}
	}

	if (n == (int)srcfield->size) {
		return n + 1;
	}

	for (; n < (int)srcfield->size; ++n, ++p) {
		switch (*p) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (++digits > COB_MAX_DIGITS || space_seen) {
				return n + 1;
			}
			continue;
		case ',':
		case '.':
			if (dec_seen || space_seen) {
				return n + 1;
			}
			if (*p == dec_pt) {
				dec_seen = 1;
			} else if (!chkcurr) {
				return n + 1;
			}
			continue;
		case ' ':
			space_seen = 1;
			continue;
		case '+':
		case '-':
			if (plus_minus) {
				return n + 1;
			}
			plus_minus = 1;
			continue;
		case 'c':
			if (!anycase) {
				return n + 1;
			}
			/* Fall through */
		case 'C':
			if (plus_minus) {
				return n + 1;
			}
			if (n < (int)srcfield->size - 1) {
				if (*(p + 1) == 'R' ||
				    (anycase && *(p + 1) == 'r')) {
					plus_minus = 1;
					p++;
					n++;
					continue;
				}
			}
			return n + 2;
		case 'd':
			if (!anycase) {
				return n + 1;
			}
			/* Fall through */
		case 'D':
			if (plus_minus) {
				return n + 1;
			}
			if (n < (int)srcfield->size - 1) {
				if (*(p + 1) == 'B' ||
				    (anycase && *(p + 1) == 'b')) {
					plus_minus = 1;
					p++;
					n++;
					continue;
				}
			}
			return n + 2;
		default:
			return n + 1;
		}
	}

	if (!digits) {
		return n + 1;
	}

	return 0;
}

/* Validate NUMVAL-F item */
/* sp = spaces */
/* [sp][+|-][sp]{digits[.[digits]]|.digits}[sp][E[sp]{+|-}[sp]digits[sp]] */

static int
cob_check_numval_f (const cob_field *srcfield)
{
	unsigned char	*p;
	size_t		plus_minus;
	size_t		digits;
	size_t		dec_seen;
	size_t		space_seen;
	size_t		e_seen;
	size_t		break_needed;
	size_t		exponent;
	size_t		e_plus_minus;
	int		n;
	unsigned char	dec_pt;

	if (!srcfield->size) {
		return 1;
	}
	p = srcfield->data;
	plus_minus = 0;
	digits = 0;
	dec_seen = 0;
	space_seen = 0;
	e_seen = 0;
	break_needed = 0;
	exponent = 0;
	e_plus_minus = 0;
	dec_pt = COB_MODULE_PTR->decimal_point;

	/* Check leading positions */
	for (n = 0; n < (int)srcfield->size; ++n, ++p) {
		switch (*p) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			break_needed = 1;
			break;
		case ' ':
			continue;
		case '+':
		case '-':
			if (plus_minus) {
				return n + 1;
			}
			plus_minus = 1;
			continue;
		case ',':
		case '.':
			if (*p != dec_pt) {
				return n + 1;
			}
			break_needed = 1;
			break;
		default:
			return n + 1;
		}
		if (break_needed) {
			break;
		}
	}

	if (n == (int)srcfield->size) {
		return n + 1;
	}

	for (; n < (int)srcfield->size; ++n, ++p) {
		switch (*p) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (e_seen) {
				if (++exponent > 4 || !e_plus_minus) {
					return n + 1;
				}
			} else if (++digits > COB_MAX_DIGITS || space_seen) {
				return n + 1;
			}
			continue;
		case ',':
		case '.':
			if (dec_seen || space_seen || e_seen) {
				return n + 1;
			}
			if (*p == dec_pt) {
				dec_seen = 1;
				continue;
			}
			return n + 1;
		case ' ':
			space_seen = 1;
			continue;
		case 'E':
			if (e_seen) {
				return n + 1;
			}
			e_seen = 1;
			continue;
		case '+':
		case '-':
			if (e_seen) {
				if (e_plus_minus) {
					return n + 1;
				}
				e_plus_minus = 1;
			} else {
				if (plus_minus) {
					return n + 1;
				}
				plus_minus = 1;
			}
			continue;
		default:
			return n + 1;
		}
	}

	if (!digits || (e_seen && !exponent)) {
		return n + 1;
	}

	return 0;
}

/* Decimal <-> GMP float */

static void
cob_decimal_set_mpf (cob_decimal *d, const mpf_t src)
{
	char		*p;
	char		*q;
	cob_sli_t	scale;
	cob_sli_t	len;

	if (!mpf_sgn (src)) {
		mpz_set_ui (d->value, 0UL);
		d->scale = 0;
		return;
	}
	q = mpf_get_str (NULL, &scale, 10, (size_t)96, src);
	p = q;
	mpz_set_str (d->value, p, 10);
	if (*p == '-') {
		++p;
	}
	len = (cob_sli_t)strlen (p);
	free (q);
	len -= scale;
	if (len >= 0) {
		d->scale = len;
	} else {
		mpz_ui_pow_ui (cob_mexp, 10UL, (cob_uli_t)-len);
		mpz_mul (d->value, d->value, cob_mexp);
		d->scale = 0;
	}
}

static void
cob_decimal_get_mpf (mpf_t dst, const cob_decimal *d)
{
	cob_sli_t	scale;

	mpf_set_z (dst, d->value);
	scale = d->scale;
	if (scale < 0) {
		mpz_ui_pow_ui (cob_mexp, 10UL, (cob_uli_t)-scale);
		mpf_set_z (cob_mpft_get, cob_mexp);
		mpf_mul (dst, dst, cob_mpft_get);
	} else if (scale > 0) {
		mpz_ui_pow_ui (cob_mexp, 10UL, (cob_uli_t)scale);
		mpf_set_z (cob_mpft_get, cob_mexp);
		mpf_div (dst, dst, cob_mpft_get);
	}
}

/* Trigonometric formulae (formulas?) from Wikipedia */


/* Exp function */
/* e ^ x = {n = 0, ...} ( (x ^ n) / n! ) */

static void
cob_mpf_exp (mpf_t dst_val, const mpf_t src_val)
{
	mpf_t			vf1, vf2, vf3;
	mpf_t			dst_temp;
	cob_sli_t		expon, i;
	cob_uli_t		n;
	cob_u32_t		is_negative;


	mpf_init2 (dst_temp, COB_MPF_PREC);

	mpf_init2 (vf1, COB_MPF_PREC);
	mpf_set (vf1, src_val);
	mpf_init2 (vf2, COB_MPF_PREC);
	mpf_set_ui (vf2, 1UL);
	mpf_init2 (vf3, COB_MPF_PREC);

	mpf_set_ui (dst_temp, 1UL);

	if (mpf_sgn (vf1) < 0) {
		mpf_neg (vf1, vf1);
		is_negative = 1;
	} else {
		is_negative = 0;
	}

	mpf_get_d_2exp (&expon, vf1);
	if (expon > 0) {
		mpf_div_2exp (vf1, vf1, (cob_uli_t)expon);
	}

	n = 1;
	do {
		mpf_mul (vf2, vf2, vf1);
		mpf_div_ui (vf2, vf2, (cob_uli_t)n);
		mpf_set (vf3, dst_temp);
		mpf_add (dst_temp, dst_temp, vf2);
		++n;
	} while (!mpf_eq (vf3, dst_temp, COB_MPF_CUTOFF));

	for (i = 0; i < expon; ++i) {
		mpf_mul (dst_temp, dst_temp, dst_temp);
	}

	if (is_negative) {
		mpf_ui_div (dst_temp, 1UL, dst_temp);
	}

	mpf_set (dst_val, dst_temp);
	mpf_clear (dst_temp);

	mpf_clear (vf3);
	mpf_clear (vf2);
	mpf_clear (vf1);
}

/* Log function */
/* logn (x) = {n = 1, ...} ( ((1 - x) ^ n) / n ) */

static void
cob_mpf_log (mpf_t dst_val, const mpf_t src_val)
{
	mpf_t			vf1, vf2, vf3, vf4;
	mpf_t			dst_temp;
	cob_sli_t		expon;
	cob_uli_t		n;



	if (mpf_sgn (src_val) <= 0 || !mpf_cmp_ui (src_val, 1UL)) {
		mpf_set_ui (dst_val, 0UL);
		return;
	}

	mpf_init2 (dst_temp, COB_MPF_PREC);

	mpf_init2 (vf1, COB_MPF_PREC);
	mpf_set (vf1, src_val);
	mpf_init2 (vf2, COB_MPF_PREC);
	mpf_init2 (vf3, COB_MPF_PREC);
	mpf_set_si (vf3, -1L);
	mpf_init2 (vf4, COB_MPF_PREC);

	mpf_set_ui (dst_temp, 0UL);
	mpf_get_d_2exp (&expon, vf1);
	if (expon != 0) {
		mpf_set (dst_temp, cob_log_half);
		if (expon > 0) {
			mpf_mul_ui (dst_temp, dst_temp, (cob_uli_t)expon);
			mpf_neg (dst_temp, dst_temp);
			mpf_div_2exp (vf1, vf1, (cob_uli_t)expon);
		} else {
			mpf_mul_ui (dst_temp, dst_temp, (cob_uli_t)-expon);
			mpf_mul_2exp (vf1, vf1, (cob_uli_t)-expon);
		}
	}
	mpf_ui_sub (vf1, 1UL, vf1);

	n = 1;
	do {
		mpf_mul (vf3, vf3, vf1);
		mpf_div_ui (vf2, vf3, n);
		mpf_set (vf4, dst_temp);
		mpf_add (dst_temp, dst_temp, vf2);
		++n;
	} while (!mpf_eq (vf4, dst_temp, COB_MPF_CUTOFF));

	mpf_set (dst_val, dst_temp);
	mpf_clear (dst_temp);

	mpf_clear (vf4);
	mpf_clear (vf3);
	mpf_clear (vf2);
	mpf_clear (vf1);
}

/* Log10 function */
/* log10 (x) = log (x) / log (10) */

static void
cob_mpf_log10 (mpf_t dst_val, const mpf_t src_val)
{
	mpf_t			vf1;
	mpf_t			dst_temp;

	mpf_init2 (dst_temp, COB_MPF_PREC);

	mpf_init2 (vf1, COB_MPF_PREC);

	cob_mpf_log (dst_temp, src_val);
	mpf_set_ui (vf1, 10UL);
	cob_mpf_log (vf1, vf1);
	mpf_div (dst_temp, dst_temp, vf1);

	mpf_set (dst_val, dst_temp);
	mpf_clear (dst_temp);

	mpf_clear (vf1);
}

/* Sin function */
/* sin (x) = (reduce to pi/2) */
/* {n = 0, ...} ( (-1 ^ n) * ( x ^ (2n + 1)) / (2n + 1) ) */

static void
cob_mpf_sin (mpf_t dst_val, const mpf_t src_val)
{
	mpf_t			vf1, vf2, vf3, vf4, vf5;
	mpf_t			dst_temp;
	cob_uli_t		arcquad;
	cob_uli_t		n;
	int			sign;

	mpf_init2 (dst_temp, COB_MPF_PREC);

	mpf_init2 (vf1, COB_MPF_PREC);
	mpf_init2 (vf2, COB_MPF_PREC);
	mpf_init2 (vf3, COB_MPF_PREC);
	mpf_init2 (vf4, COB_MPF_PREC);
	mpf_init2 (vf5, COB_MPF_PREC);
	sign = mpf_sgn (src_val);

	mpf_abs (vf4, src_val);
	mpf_set (vf3, cob_pi);
	mpf_div_2exp (vf3, vf3, 1UL);
	mpf_div (vf1, vf4, vf3);
	mpf_floor (vf4, vf1);

	if (mpf_cmp_ui (vf4, 4UL) >= 0) {
		mpf_div_2exp (vf2, vf4, 2UL);
		mpf_floor (vf2, vf2);
		mpf_mul_2exp (vf2, vf2, 2UL);
		mpf_sub (vf2, vf4, vf2);
	} else {
		mpf_set (vf2, vf4);
	}

	arcquad = mpf_get_ui (vf2);
	mpf_sub (vf2, vf1, vf4);
	mpf_mul (vf4, vf3, vf2);

	if (arcquad > 1) {
		sign = -sign;
	}
	if (arcquad & 1) {
		mpf_sub (vf4, vf3, vf4);
	}

	mpf_mul (vf3, vf4, vf4);
	mpf_neg (vf3, vf3);

	n = 1;
	mpf_set_ui (vf2, 1UL);
	mpf_set_ui (dst_temp, 1UL);

	do {
		++n;
		mpf_div_ui (vf2, vf2, n);
		++n;
		mpf_div_ui (vf2, vf2, n);
		mpf_mul (vf2, vf2, vf3);
		mpf_set (vf5, dst_temp);
		mpf_add (dst_temp, dst_temp, vf2);
	} while (!mpf_eq (vf5, dst_temp, COB_MPF_PREC));

	mpf_mul (dst_temp, dst_temp, vf4);
	if (sign < 0) {
		mpf_neg (dst_temp, dst_temp);
	}

	mpf_set (dst_val, dst_temp);
	mpf_clear (dst_temp);

	mpf_clear (vf5);
	mpf_clear (vf4);
	mpf_clear (vf3);
	mpf_clear (vf2);
	mpf_clear (vf1);
}

/* Cos function */
/* cos (x) = sin ((pi / 2) - x) */

static void
cob_mpf_cos (mpf_t dst_val, const mpf_t src_val)
{
	mpf_t		vf1;

	mpf_init2 (vf1, COB_MPF_PREC);

	mpf_set (vf1, cob_pi);
	mpf_div_2exp (vf1, vf1, 1UL);
	mpf_sub (vf1, vf1, src_val);
	cob_mpf_sin (dst_val, vf1);

	mpf_clear (vf1);
}

/* Tan function */
/* tan (x) = sin(x) / cos(x) */

static void
cob_mpf_tan (mpf_t dst_val, const mpf_t src_val)
{
	mpf_t		vf1;
	mpf_t		vf2;

	mpf_init2 (vf1, COB_MPF_PREC);
	mpf_init2 (vf2, COB_MPF_PREC);

	cob_mpf_sin (vf1, src_val);
	cob_mpf_cos (vf2, src_val);
	mpf_div (dst_val, vf1, vf2);

	mpf_clear (vf1);
	mpf_clear (vf2);
}

/* Atan function */

static void
cob_mpf_atan (mpf_t dst_val, const mpf_t src_val)
{
	mpf_t			vf1, vf2, vf3, vf4;
	mpf_t			dst_temp;
	cob_uli_t		n;

	mpf_init2 (dst_temp, COB_MPF_PREC);

	mpf_init2 (vf1, COB_MPF_PREC);
	mpf_init2 (vf2, COB_MPF_PREC);
	mpf_init2 (vf3, COB_MPF_PREC);
	mpf_init2 (vf4, COB_MPF_PREC);

	mpf_abs (vf1, src_val);
	mpf_add_ui (vf3, cob_sqrt_two, 1UL);

	if (mpf_cmp (vf1, vf3) > 0) {
		mpf_set (dst_temp, cob_pi);
		mpf_div_2exp (dst_temp, dst_temp, 1UL);
		mpf_ui_div (vf1, 1UL, vf1);
		mpf_neg (vf1, vf1);
	} else {
		mpf_sub_ui (vf4, cob_sqrt_two, 1UL);
		if (mpf_cmp (vf1, vf4) > 0) {
			mpf_set (dst_temp, cob_pi);
			mpf_div_2exp (dst_temp, dst_temp, 2UL);
			mpf_sub_ui (vf3, vf1, 1UL);
			mpf_add_ui (vf4, vf1, 1UL);
			mpf_div (vf1, vf3, vf4);
		} else {
			mpf_set_ui (dst_temp, 0UL);
		}
	}
	mpf_mul (vf2, vf1, vf1);
	mpf_neg (vf2, vf2);
	mpf_add (dst_temp, dst_temp, vf1);

	n = 1;

	do {
		mpf_mul (vf1, vf1, vf2);
		mpf_div_ui (vf3, vf1, 2UL * n + 1UL);
		mpf_set (vf4, dst_temp);
		mpf_add (dst_temp, dst_temp, vf3);
		++n;
	} while (!mpf_eq (vf4, dst_temp, COB_MPF_PREC));

	if (mpf_sgn (src_val) < 0) {
		mpf_neg (dst_temp, dst_temp);
	}

	mpf_set (dst_val, dst_temp);
	mpf_clear (dst_temp);

	mpf_clear (vf4);
	mpf_clear (vf3);
	mpf_clear (vf2);
	mpf_clear (vf1);
}

/* Asin function */
/* asin (x) = 2 * atan (x / (1 + sqrt (1 - (x ** 2)))) */

static void
cob_mpf_asin (mpf_t dst_val, const mpf_t src_val)
{
	mpf_t			vf1, vf2;
	mpf_t			dst_temp;

	mpf_init2 (dst_temp, COB_MPF_PREC);

	if (!mpf_cmp_ui (src_val, 1UL) || !mpf_cmp_si (src_val, -1L)) {
		mpf_set (dst_temp, cob_pi);
		mpf_div_ui (dst_temp, dst_temp, 2UL);
		if (mpf_sgn (src_val) < 0) {
			mpf_neg (dst_temp, dst_temp);
		}
		mpf_set (dst_val, dst_temp);
		mpf_clear (dst_temp);
		return;
	}
	if (!mpz_sgn (src_val)) {
		mpf_set_ui (dst_val, 0UL);
		mpf_clear (dst_temp);
		return;
	}

	mpf_init2 (vf1, COB_MPF_PREC);
	mpf_init2 (vf2, COB_MPF_PREC);

	mpf_mul (vf2, src_val, src_val);
	mpf_ui_sub (vf2, 1UL, vf2);
	mpf_sqrt (vf2, vf2);

	mpf_add_ui (vf2, vf2, 1UL);

	mpf_div (vf1, src_val, vf2);
	cob_mpf_atan (dst_temp, vf1);
	mpf_mul_ui (dst_temp, dst_temp, 2UL);

	mpf_set (dst_val, dst_temp);
	mpf_clear (dst_temp);

	mpf_clear (vf2);
	mpf_clear (vf1);
}

/* Acos function */
/* acos (x) = 2 * atan (sqrt (1 - (x ** 2)) / (1 + x)) */

static void
cob_mpf_acos (mpf_t dst_val, const mpf_t src_val)
{
	mpf_t			vf1, vf2;
	mpf_t			dst_temp;

	mpf_init2 (dst_temp, COB_MPF_PREC);

	if (!mpf_sgn (src_val)) {
		mpf_set (dst_temp, cob_pi);
		mpf_div_ui (dst_temp, dst_temp, 2UL);
		mpf_set (dst_val, dst_temp);
		mpf_clear (dst_temp);
		return;
	}
	if (!mpf_cmp_ui (src_val, 1UL)) {
		mpf_set_ui (dst_val, 0UL);
		mpf_clear (dst_temp);
		return;
	}
	if (!mpf_cmp_si (src_val, -1L)) {
		mpf_set (dst_val, cob_pi);
		mpf_clear (dst_temp);
		return;
	}

	mpf_init2 (vf1, COB_MPF_PREC);
	mpf_init2 (vf2, COB_MPF_PREC);

	mpf_add_ui (vf2, src_val, 1UL);
	mpf_mul (vf1, src_val, src_val);
	mpf_ui_sub (vf1, 1UL, vf1);
	mpf_sqrt (vf1, vf1);
	mpf_div (vf1, vf1, vf2);
	cob_mpf_atan (dst_temp, vf1);
	mpf_mul_ui (dst_temp, dst_temp, 2UL);

	mpf_set (dst_val, dst_temp);
	mpf_clear (dst_temp);

	mpf_clear (vf2);
	mpf_clear (vf1);
}


/* Global functions */

/* Return switch value as field */

cob_field *
cob_switch_value (const int id)
{
	cob_alloc_set_field_int (cob_get_switch (id));
	return curr_field;
}

/* Decimal exponentiation function */
/* x ^ z = e ^ (z * log(x)) */

void
cob_decimal_pow (cob_decimal *pd1, cob_decimal *pd2)
{
	cob_uli_t		n;
	int			sign;

	if (unlikely(pd1->scale == COB_DECIMAL_NAN)) {
		return;
	}
	if (unlikely(pd2->scale == COB_DECIMAL_NAN)) {
		pd1->scale = COB_DECIMAL_NAN;
		return;
	}

	sign = mpz_sgn (pd1->value);

	if (!mpz_sgn (pd2->value)) {
		/* Exponent is zero */
		if (!sign) {
			/* 0 ^ 0 */
			cob_set_exception (COB_EC_SIZE_EXPONENTIATION);
		}
		mpz_set_ui (pd1->value, 1UL);
		pd1->scale = 0;
		return;
	}
	if (!sign) {
		/* Value is zero */
		pd1->scale = 0;
		return;
	}

	cob_trim_decimal (pd2);

	if (sign < 0 && pd2->scale) {
		/* Negative exponent and non-integer power */
		pd1->scale = COB_DECIMAL_NAN;
		cob_set_exception (COB_EC_SIZE_EXPONENTIATION);
		return;
	}

	cob_trim_decimal (pd1);

	if (!pd2->scale) {
		/* Integer power */
		if (!mpz_cmp_ui (pd2->value, 1UL)) {
			/* Power is 1 */
			return;
		}
		if (mpz_sgn (pd2->value) < 0 && mpz_fits_slong_p (pd2->value)) {
			/* Negative power */
			mpz_abs (pd2->value, pd2->value);
			n = mpz_get_ui (pd2->value);
			mpz_pow_ui (pd1->value, pd1->value, n);
			if (pd1->scale) {
				pd1->scale *= n;
				cob_trim_decimal (pd1);
			}
			cob_decimal_set (pd2, pd1);
			mpz_set_ui (pd1->value, 1UL),
			pd1->scale = 0;
			cob_decimal_div (pd1, pd2);
			cob_trim_decimal (pd1);
			return;
		}
		if (mpz_fits_ulong_p (pd2->value)) {
			/* Positive power */
			n = mpz_get_ui (pd2->value);
			mpz_pow_ui (pd1->value, pd1->value, n);
			if (pd1->scale) {
				pd1->scale *= n;
				cob_trim_decimal (pd1);
			}
			return;
		}
	}

	if (sign < 0) {
		mpz_abs (pd1->value, pd1->value);
	}
	cob_decimal_get_mpf (cob_mpft, pd1);
	if (pd2->scale == 1 && !mpz_cmp_ui (pd2->value, 5UL)) {
		/* Square root short cut */
		mpf_sqrt (cob_mpft2, cob_mpft);
	} else {
		cob_decimal_get_mpf (cob_mpft2, pd2);
		cob_mpf_log (cob_mpft, cob_mpft);
		mpf_mul (cob_mpft, cob_mpft, cob_mpft2);
		cob_mpf_exp (cob_mpft2, cob_mpft);
	}
	cob_decimal_set_mpf (pd1, cob_mpft2);
	if (sign < 0) {
		mpz_neg (pd1->value, pd1->value);
	}
}

/* Indirect field get/put functions */

void
cob_put_indirect_field (cob_field *f)
{
	make_field_entry (f);
	memcpy (curr_field->data, f->data, f->size);
	move_field = curr_field;
}

void
cob_get_indirect_field (cob_field *f)
{
	cob_move (move_field, f);
}

/* Indirect move */

void
cob_decimal_move_temp (cob_field *src, cob_field *dst)
{
	int		size;
	int		scale;
	cob_field_attr	attr;
	cob_field	field;

	cob_decimal_set_field (&d1, src);
	cob_trim_decimal (&d1);

	size = (int)mpz_sizeinbase (d1.value, 10);
	if (d1.scale > size) {
		size = d1.scale;
	}
	scale = d1.scale;
	COB_ATTR_INIT (COB_TYPE_NUMERIC_DISPLAY, size,
		       scale, COB_FLAG_HAVE_SIGN, NULL);
	COB_FIELD_INIT (size, NULL, &attr);
	make_field_entry (&field);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	cob_move (curr_field, dst);
}

/* Numeric expressions */

cob_field *
cob_intr_binop (cob_field *f1, const int op, cob_field *f2)
{
	cob_decimal_set_field (&d1, f1);
	cob_decimal_set_field (&d2, f2);
	switch (op) {
	case '+':
		cob_decimal_add (&d1, &d2);
		break;
	case '-':
		cob_decimal_sub (&d1, &d2);
		break;
	case '*':
		cob_decimal_mul (&d1, &d2);
		break;
	case '/':
		cob_set_exception (0);
		if (!mpz_sgn (d2.value)) {
			/* Divide by zero */
			cob_set_exception (COB_EC_SIZE_ZERO_DIVIDE);
			mpz_set_ui (d1.value, 0UL);
			d1.scale = 0;
		} else {
			cob_decimal_div (&d1, &d2);
		}
		break;
	case '^':
		cob_decimal_pow (&d1, &d2);
		break;
	default:
		break;
	}

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

/* Intrinsics */

cob_field *
cob_intr_length (cob_field *srcfield)
{
	if (COB_FIELD_IS_NATIONAL (srcfield)) {
		cob_alloc_set_field_uint ((cob_u32_t)srcfield->size / COB_NATIONAL_SIZE);
	} else {
		cob_alloc_set_field_uint ((cob_u32_t)srcfield->size);
	}
	return curr_field;
}

cob_field *
cob_intr_byte_length (cob_field *srcfield)
{
	cob_alloc_set_field_uint ((cob_u32_t)srcfield->size);
	return curr_field;
}

cob_field *
cob_intr_integer (cob_field *srcfield)
{
	int		sign;

	cob_decimal_set_field (&d1, srcfield);
	/* Check scale */
	if (d1.scale < 0) {
		mpz_ui_pow_ui (cob_mexp, 10UL, (cob_uli_t)-d1.scale);
		mpz_mul (d1.value, d1.value, cob_mexp);
	} else if (d1.scale > 0) {
		sign = mpz_sgn (d1.value);
		mpz_ui_pow_ui (cob_mexp, 10UL, (cob_uli_t)d1.scale);
		mpz_tdiv_qr (d1.value, cob_mpzt, d1.value, cob_mexp);
		/* Check negative and has decimal places */
		if (sign < 0 && mpz_sgn (cob_mpzt)) {
			mpz_sub_ui (d1.value, d1.value, 1UL);
		}
	}
	d1.scale = 0;

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_integer_part (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);
	/* Check scale */
	if (d1.scale < 0) {
		mpz_ui_pow_ui (cob_mexp, 10UL, (cob_uli_t)-d1.scale);
		mpz_mul (d1.value, d1.value, cob_mexp);
	} else if (d1.scale > 0) {
		mpz_ui_pow_ui (cob_mexp, 10UL, (cob_uli_t)d1.scale);
		mpz_tdiv_q (d1.value, d1.value, cob_mexp);
	}
	d1.scale = 0;

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_fraction_part (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);
	/* Check scale */
	if (d1.scale > 0) {
		mpz_ui_pow_ui (cob_mexp, 10UL, (cob_uli_t)d1.scale);
		mpz_tdiv_r (d1.value, d1.value, cob_mexp);
	} else {
		/* No decimals */
		mpz_set_ui (d1.value, 0UL);
		d1.scale = 0;
	}

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_sign (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);
	cob_alloc_set_field_int (mpz_sgn (d1.value));
	return curr_field;
}

cob_field *
cob_intr_upper_case (const int offset, const int length, cob_field *srcfield)
{
	size_t		i, size;

	make_field_entry (srcfield);

	size = srcfield->size;
	for (i = 0; i < size; ++i) {
		curr_field->data[i] = (cob_u8_t)toupper (srcfield->data[i]);
	}
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	return curr_field;
}

cob_field *
cob_intr_lower_case (const int offset, const int length, cob_field *srcfield)
{
	size_t		i, size;

	make_field_entry (srcfield);

	size = srcfield->size;
	for (i = 0; i < size; ++i) {
		curr_field->data[i] = (cob_u8_t)tolower (srcfield->data[i]);
	}
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	return curr_field;
}

cob_field *
cob_intr_reverse (const int offset, const int length, cob_field *srcfield)
{
	size_t		i, size;

	make_field_entry (srcfield);

	size = srcfield->size;
	for (i = 0; i < size; ++i) {
		curr_field->data[i] = srcfield->data[size - i - 1];
	}
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	return curr_field;
}

cob_field *
cob_intr_module_date (void)
{
	cob_field_attr	attr;
	cob_field	field;
	char		buff[16];

	COB_ATTR_INIT (COB_TYPE_NUMERIC_DISPLAY, 8, 0, 0, NULL);
	COB_FIELD_INIT (8, NULL, &attr);
	make_field_entry (&field);
	snprintf (buff, sizeof(buff), "%8.8u", COB_MODULE_PTR->module_date);
	memcpy (curr_field->data, buff, (size_t)8);
	return curr_field;
}

cob_field *
cob_intr_module_time (void)
{
	cob_field_attr	attr;
	cob_field	field;
	char		buff[8];

	COB_ATTR_INIT (COB_TYPE_NUMERIC_DISPLAY, 6, 0, 0, NULL);
	COB_FIELD_INIT (6, NULL, &attr);
	make_field_entry (&field);
	snprintf (buff, sizeof(buff), "%6.6u", COB_MODULE_PTR->module_time);
	memcpy (curr_field->data, buff, (size_t)6);
	return curr_field;
}

cob_field *
cob_intr_module_id (void)
{
	size_t		calcsize;
	cob_field	field;

	calcsize = strlen (COB_MODULE_PTR->module_name);
	COB_FIELD_INIT (calcsize, NULL, &const_alpha_attr);
	make_field_entry (&field);
	memcpy (curr_field->data, COB_MODULE_PTR->module_name, calcsize);
	return curr_field;
}

cob_field *
cob_intr_module_caller_id (void)
{
	size_t		calcsize;
	cob_field	field;

	if (!COB_MODULE_PTR->next) {
		COB_FIELD_INIT (1, NULL, &const_alpha_attr);
		make_field_entry (&field);
		curr_field->size = 0;
		curr_field->data[0] = ' ';
		return curr_field;
	}
	calcsize = strlen (COB_MODULE_PTR->next->module_name);
	COB_FIELD_INIT (calcsize, NULL, &const_alpha_attr);
	make_field_entry (&field);
	memcpy (curr_field->data, COB_MODULE_PTR->next->module_name,
		calcsize);
	return curr_field;
}

cob_field *
cob_intr_module_formatted_date (void)
{
	size_t		calcsize;
	cob_field	field;

	calcsize = strlen (COB_MODULE_PTR->module_formatted_date);
	COB_FIELD_INIT (calcsize, NULL, &const_alpha_attr);
	make_field_entry (&field);
	memcpy (curr_field->data, COB_MODULE_PTR->module_formatted_date,
		calcsize);
	return curr_field;
}

cob_field *
cob_intr_module_source (void)
{
	size_t		calcsize;
	cob_field	field;

	calcsize = strlen (COB_MODULE_PTR->module_source);
	COB_FIELD_INIT (calcsize, NULL, &const_alpha_attr);
	make_field_entry (&field);
	memcpy (curr_field->data, COB_MODULE_PTR->module_source, calcsize);
	return curr_field;
}

cob_field *
cob_intr_module_path (void)
{
	size_t		calcsize;
	cob_field	field;

	if (!COB_MODULE_PTR->module_path ||
	    !*(COB_MODULE_PTR->module_path)) {
		COB_FIELD_INIT (1, NULL, &const_alpha_attr);
		make_field_entry (&field);
		curr_field->size = 0;
		curr_field->data[0] = ' ';
		return curr_field;
	}
	calcsize = strlen (*(COB_MODULE_PTR->module_path));
	COB_FIELD_INIT (calcsize, NULL, &const_alpha_attr);
	make_field_entry (&field);
	memcpy (curr_field->data, *(COB_MODULE_PTR->module_path),
		calcsize);
	return curr_field;
}

cob_field *
cob_intr_concatenate (const int offset, const int length,
		      const int params, ...)
{
	cob_field	**f;
	unsigned char	*p;
	size_t		calcsize;
	int		i;
	cob_field	field;
	va_list		args;

	f = cob_malloc ((size_t)params * sizeof (cob_field *));

	va_start (args, params);

	/* Extract args / calculate size */
	calcsize = 0;
	for (i = 0; i < params; ++i) {
		f[i] = va_arg (args, cob_field *);
		calcsize += f[i]->size;
	}
	va_end (args);

	COB_FIELD_INIT (calcsize, NULL, &const_alpha_attr);
	make_field_entry (&field);

	p = curr_field->data;
	for (i = 0; i < params; ++i) {
		memcpy (p, f[i]->data, f[i]->size);
		p += f[i]->size;
	}

	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	free (f);
	return curr_field;
}

cob_field *
cob_intr_substitute (const int offset, const int length,
		     const int params, ...)
{
	cob_field	*var;
	cob_field	**f1;
	cob_field	**f2;
	unsigned char	*p1;
	unsigned char	*p2;
	size_t		varsize;
	size_t		calcsize;
	size_t		n;
	size_t		found;
	int		numreps;
	int		i;
	cob_field	field;
	va_list		args;

	numreps = params / 2;
	f1 = cob_malloc ((size_t)numreps * sizeof (cob_field *));
	f2 = cob_malloc ((size_t)numreps * sizeof (cob_field *));

	va_start (args, params);

	var = va_arg (args, cob_field *);
	varsize = var->size;

	/* Extract args */
	for (i = 0; i < params - 1; ++i) {
		if ((i % 2) == 0) {
			f1[i / 2] = va_arg (args, cob_field *);
		} else {
			f2[i / 2] = va_arg (args, cob_field *);
		}
	}
	va_end (args);

	/* Calculate required size */
	calcsize = 0;
	found = 0;
	p1 = var->data;
	for (n = 0; n < varsize; ) {
		for (i = 0; i < numreps; ++i) {
			if (n + f1[i]->size <= varsize) {
				if (!memcmp (p1, f1[i]->data, f1[i]->size)) {
					p1 += f1[i]->size;
					n += f1[i]->size;
					calcsize += f2[i]->size;
					found = 1;
					break;
				}
			}
		}
		if (found) {
			found = 0;
			continue;
		}
		++n;
		++p1;
		++calcsize;
	}

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	field.size = calcsize;
	make_field_entry (&field);

	found = 0;
	p1 = var->data;
	p2 = curr_field->data;
	for (n = 0; n < varsize; ) {
		for (i = 0; i < numreps; ++i) {
			if (n + f1[i]->size <= varsize) {
				if (!memcmp (p1, f1[i]->data, f1[i]->size)) {
					memcpy (p2, f2[i]->data, f2[i]->size);
					p1 += f1[i]->size;
					p2 += f2[i]->size;
					n += f1[i]->size;
					found = 1;
					break;
				}
			}
		}
		if (found) {
			found = 0;
			continue;
		}
		++n;
		*p2++ = *p1++;
	}
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	free (f1);
	free (f2);
	return curr_field;
}

cob_field *
cob_intr_substitute_case (const int offset, const int length,
			  const int params, ...)
{
	cob_field	*var;
	cob_field	**f1;
	cob_field	**f2;
	unsigned char	*p1;
	unsigned char	*p2;
	size_t		varsize;
	size_t		calcsize;
	size_t		n;
	size_t		found;
	int		numreps;
	int		i;
	cob_field	field;
	va_list		args;

	numreps = params / 2;
	f1 = cob_malloc ((size_t)numreps * sizeof (cob_field *));
	f2 = cob_malloc ((size_t)numreps * sizeof (cob_field *));

	va_start (args, params);

	var = va_arg (args, cob_field *);
	varsize = var->size;

	/* Extract args */
	for (i = 0; i < params - 1; ++i) {
		if ((i % 2) == 0) {
			f1[i / 2] = va_arg (args, cob_field *);
		} else {
			f2[i / 2] = va_arg (args, cob_field *);
		}
	}
	va_end (args);

	/* Calculate required size */
	calcsize = 0;
	found = 0;
	p1 = var->data;
	for (n = 0; n < varsize; ) {
		for (i = 0; i < numreps; ++i) {
			if (n + f1[i]->size <= varsize) {
				if (!strncasecmp ((const char *)p1,
						  (const char *)(f1[i]->data),
						  f1[i]->size)) {
					p1 += f1[i]->size;
					n += f1[i]->size;
					calcsize += f2[i]->size;
					found = 1;
					break;
				}
			}
		}
		if (found) {
			found = 0;
			continue;
		}
		++n;
		++p1;
		++calcsize;
	}

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	field.size = calcsize;
	make_field_entry (&field);

	found = 0;
	p1 = var->data;
	p2 = curr_field->data;
	for (n = 0; n < varsize; ) {
		for (i = 0; i < numreps; ++i) {
			if (n + f1[i]->size <= varsize) {
				if (!strncasecmp ((const char *)p1,
						  (const char *)(f1[i]->data),
						  f1[i]->size)) {
					memcpy (p2, f2[i]->data, f2[i]->size);
					p1 += f1[i]->size;
					p2 += f2[i]->size;
					n += f1[i]->size;
					found = 1;
					break;
				}
			}
		}
		if (found) {
			found = 0;
			continue;
		}
		++n;
		*p2++ = *p1++;
	}
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	free (f1);
	free (f2);
	return curr_field;
}

cob_field *
cob_intr_trim (const int offset, const int length,
		cob_field *srcfield, const int direction)
{
	unsigned char	*begin;
	unsigned char	*end;
	size_t		i;
	size_t		size;

	make_field_entry (srcfield);

	for (i = 0; i < srcfield->size; ++i) {
		if (srcfield->data[i] != ' ') {
			break;
		}
	}
	if (i == srcfield->size) {
		curr_field->size = 0;
		curr_field->data[0] = ' ';
		return curr_field;
	}

	begin = srcfield->data;
	if (direction != 2) {
		for (; *begin == ' '; ++begin) ;
	}
	end = srcfield->data + srcfield->size - 1;
	if (direction != 1) {
		for (; *end == ' '; end--) ;
	}

	size = 0;
	for (i = 0; begin <= end; ++begin, ++i) {
		curr_field->data[i] = *begin;
		++size;
	}
	curr_field->size = size;
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	return curr_field;
}

cob_field *
cob_intr_exception_file (void)
{
	size_t		flen;
	cob_field	field;

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	if (cobglobptr->cob_exception_code == 0 || !cobglobptr->cob_error_file ||
	    (cobglobptr->cob_exception_code & 0x0500) != 0x0500) {
		field.size = 2;
		make_field_entry (&field);
		memcpy (curr_field->data, "00", (size_t)2);
	} else {
		flen = strlen (cobglobptr->cob_error_file->select_name);
		field.size = flen + 2;
		make_field_entry (&field);
		memcpy (curr_field->data,
			cobglobptr->cob_error_file->file_status, (size_t)2);
		memcpy (&(curr_field->data[2]),
			cobglobptr->cob_error_file->select_name, flen);
	}
	return curr_field;
}

cob_field *
cob_intr_exception_location (void)
{
	char		*buff;
	cob_field	field;

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	if (!cobglobptr->cob_got_exception || !cobglobptr->cob_orig_program_id) {
		field.size = 1;
		make_field_entry (&field);
		*(curr_field->data) = ' ';
		return curr_field;
	}
	buff = cob_malloc ((size_t)COB_SMALL_BUFF);
	if (cobglobptr->cob_orig_section && cobglobptr->cob_orig_paragraph) {
		snprintf (buff, (size_t)COB_SMALL_MAX, "%s; %s OF %s; %u",
			  cobglobptr->cob_orig_program_id,
			  cobglobptr->cob_orig_paragraph,
			  cobglobptr->cob_orig_section,
			  cobglobptr->cob_orig_line);
	} else if (cobglobptr->cob_orig_section) {
		snprintf (buff, (size_t)COB_SMALL_MAX, "%s; %s; %u",
			  cobglobptr->cob_orig_program_id,
			  cobglobptr->cob_orig_section,
			  cobglobptr->cob_orig_line);
	} else if (cobglobptr->cob_orig_paragraph) {
		snprintf (buff, (size_t)COB_SMALL_MAX, "%s; %s; %u",
			  cobglobptr->cob_orig_program_id,
			  cobglobptr->cob_orig_paragraph,
			  cobglobptr->cob_orig_line);
	} else {
		snprintf (buff, (size_t)COB_SMALL_MAX, "%s; ; %u",
			  cobglobptr->cob_orig_program_id,
			  cobglobptr->cob_orig_line);
	}
	field.size = strlen (buff);
	make_field_entry (&field);
	memcpy (curr_field->data, buff, field.size);
	free (buff);
	return curr_field;
}

cob_field *
cob_intr_exception_status (void)
{
	const char	*except_name;
	cob_field	field;

	COB_FIELD_INIT (31, NULL, &const_alpha_attr);
	make_field_entry (&field);

	memset (curr_field->data, ' ', (size_t)31);
	if (cobglobptr->cob_exception_code) {
		except_name = cob_get_exception_name ();
		if (except_name == NULL) {
			except_name = "EXCEPTION-OBJECT";
		}
		memcpy (curr_field->data, except_name, strlen (except_name));
	}
	return curr_field;
}

cob_field *
cob_intr_exception_statement (void)
{
	size_t		flen;
	cob_field	field;

	COB_FIELD_INIT (31, NULL, &const_alpha_attr);
	make_field_entry (&field);

	memset (curr_field->data, ' ', (size_t)31);
	if (cobglobptr->cob_exception_code && cobglobptr->cob_orig_statement) {
		flen = strlen (cobglobptr->cob_orig_statement);
		if (flen > 31) {
			memcpy (curr_field->data,
				cobglobptr->cob_orig_statement, (size_t)31);
		} else {
			memcpy (curr_field->data,
				cobglobptr->cob_orig_statement, flen);
		}
	}
	return curr_field;
}

cob_field *
cob_intr_when_compiled (const int offset, const int length, cob_field *f)
{
	make_field_entry (f);

	memcpy (curr_field->data, f->data, f->size);
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	return curr_field;
}

cob_field *
cob_intr_current_date (const int offset, const int length)
{
#if	defined(_WIN32) && !defined(__CYGWIN__)
	struct tm	*tmptr;
	long		contz;
	struct _timeb	tmb;
	cob_field	field;
#else

	struct tm	*tmptr;
#if !defined(__linux__) && !defined(__CYGWIN__) && !defined(COB_STRFTIME) && defined(HAVE_TIMEZONE)
	long		contz;
#endif
	time_t		curtime;
	cob_field	field;
#if defined(HAVE_SYS_TIME_H) && defined(HAVE_GETTIMEOFDAY)
	struct timeval	tmv;
	char		buff2[8];
#endif
#endif
	char		buff[24];

	COB_FIELD_INIT (21, NULL, &const_alpha_attr);
	make_field_entry (&field);
	memset (buff, 0, sizeof(buff));

#if	defined(_WIN32) && !defined(__CYGWIN__)
	_ftime (&tmb);
	tmptr = localtime (&(tmb.time));
	/* Leap seconds ? */
	if (tmptr->tm_sec >= 60) {
		tmptr->tm_sec = 59;
	}
	if (tmb.timezone <= 0) {
		contz = -tmb.timezone;
		snprintf (buff, (size_t)23,
			"%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d%2.2d+%2.2ld%2.2ld",
			tmptr->tm_year + 1900, tmptr->tm_mon + 1, tmptr->tm_mday,
			tmptr->tm_hour, tmptr->tm_min, tmptr->tm_sec,
			tmb.millitm / 100, contz / 60, contz % 60);
	} else {
		contz = tmb.timezone;
		snprintf (buff, (size_t)23,
			"%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d%2.2d-%2.2ld%2.2ld",
			tmptr->tm_year + 1900, tmptr->tm_mon + 1, tmptr->tm_mday,
			tmptr->tm_hour, tmptr->tm_min, tmptr->tm_sec,
			tmb.millitm / 100, contz / 60, contz % 60);
	}
#else	/* defined(_WIN32) && !defined(__CYGWIN__) */

#if defined(HAVE_SYS_TIME_H) && defined(HAVE_GETTIMEOFDAY)
	gettimeofday (&tmv, NULL);
	curtime = tmv.tv_sec;
#else
	curtime = time (NULL);
#endif
	tmptr = localtime (&curtime);
	/* Leap seconds ? */
	if (tmptr->tm_sec >= 60) {
		tmptr->tm_sec = 59;
	}

#if defined(__linux__) || defined(__CYGWIN__) || defined(COB_STRFTIME)
	strftime (buff, (size_t)22, "%Y%m%d%H%M%S00%z", tmptr);
#elif defined(HAVE_TIMEZONE)
	strftime (buff, (size_t)17, "%Y%m%d%H%M%S00", tmptr);
	contz = timezone;
	if (tmptr->tm_isdst > 0) {
		contz -= 3600;
	}
	if (contz <= 0) {
		contz = -contz;
		buff[16] = '+';
	} else {
		buff[16] = '-';
	}
	sprintf(&buff[17], "%2.2ld%2.2ld", contz / 3600, (contz % 3600) / 60);
#else
	strftime (buff, (size_t)22, "%Y%m%d%H%M%S0000000", tmptr);
#endif

#if defined(HAVE_SYS_TIME_H) && defined(HAVE_GETTIMEOFDAY)
	snprintf(buff2, (size_t)7, "%2.2ld", tmv.tv_usec / 10000);
	memcpy (&buff[14], buff2, (size_t)2);
#endif
#endif

	memcpy (curr_field->data, buff, (size_t)21);
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	return curr_field;
}

cob_field *
cob_intr_char (cob_field *srcfield)
{
	int		i;
	cob_field	field;

	COB_FIELD_INIT (1, NULL, &const_alpha_attr);
	make_field_entry (&field);

	i = cob_get_int (srcfield);
	if (i < 1 || i > 256) {
		*curr_field->data = 0;
	} else {
		*curr_field->data = i - 1;
	}
	return curr_field;
}

cob_field *
cob_intr_ord (cob_field *srcfield)
{
	cob_alloc_set_field_uint ((cob_u32_t)(*srcfield->data + 1U));
	return curr_field;
}

cob_field *
cob_intr_stored_char_length (cob_field *srcfield)
{
	unsigned char	*p;
	cob_u32_t	count;

	count = srcfield->size;
	p = srcfield->data + srcfield->size - 1;
	for (; count > 0; count--, p--) {
		if (*p != ' ') {
			break;
		}
	}

	cob_alloc_set_field_uint (count);
	return curr_field;
}

cob_field *
cob_intr_combined_datetime (cob_field *srcdays, cob_field *srctime)
{
	int		srdays;
	int		srtime;
	cob_field_attr	attr;
	cob_field	field;
	char		buff[16];

	COB_ATTR_INIT (COB_TYPE_NUMERIC_DISPLAY, 12, 5, 0, NULL);
	COB_FIELD_INIT (12, NULL, &attr);
	make_field_entry (&field);

	cob_set_exception (0);
	srdays = cob_get_int (srcdays);
	if (srdays < 1 || srdays > 3067671) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		memset (curr_field->data, '0', (size_t)12);
		return curr_field;
	}
	srtime = cob_get_int (srctime);
	if (srtime < 1 || srtime > 86400) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		memset (curr_field->data, '0', (size_t)12);
		return curr_field;
	}
	snprintf (buff, (size_t)15, "%7.7d%5.5d", srdays, srtime);
	memcpy (curr_field->data, buff, (size_t)12);
	return curr_field;
}

cob_field *
cob_intr_date_of_integer (cob_field *srcdays)
{
	int		i;
	int		days;
	int		baseyear;
	int		leapyear;
	cob_field_attr	attr;
	cob_field	field;
	char		buff[16];

	COB_ATTR_INIT (COB_TYPE_NUMERIC_DISPLAY, 8, 0, 0, NULL);
	COB_FIELD_INIT (8, NULL, &attr);
	make_field_entry (&field);

	cob_set_exception (0);
	/* Base 1601-01-01 */
	days = cob_get_int (srcdays);
	if (days < 1 || days > 3067671) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		memset (curr_field->data, '0', (size_t)8);
		return curr_field;
	}
	baseyear = 1601;
	leapyear = 365;
	while (days > leapyear) {
		days -= leapyear;
		++baseyear;
		if (leap_year (baseyear)) {
			leapyear = 366;
		} else {
			leapyear = 365;
		}
	}
	for (i = 0; i < 13; ++i) {
		if (leap_year (baseyear)) {
			if (days <= leap_days[i]) {
				days -= leap_days[i-1];
				break;
			}
		} else {
			if (days <= normal_days[i]) {
				days -= normal_days[i-1];
				break;
			}
		}
	}
	snprintf (buff, (size_t)15, "%4.4d%2.2d%2.2d", baseyear, i, days);
	memcpy (curr_field->data, buff, (size_t)8);
	return curr_field;
}

cob_field *
cob_intr_day_of_integer (cob_field *srcdays)
{
	int		days;
	int		baseyear;
	int		leapyear;
	cob_field_attr	attr;
	cob_field	field;
	char		buff[16];

	COB_ATTR_INIT (COB_TYPE_NUMERIC_DISPLAY, 7, 0, 0, NULL);
	COB_FIELD_INIT (7, NULL, &attr);
	make_field_entry (&field);

	cob_set_exception (0);
	/* Base 1601-01-01 */
	days = cob_get_int (srcdays);
	if (days < 1 || days > 3067671) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		memset (curr_field->data, '0', (size_t)7);
		return curr_field;
	}
	baseyear = 1601;
	leapyear = 365;
	while (days > leapyear) {
		days -= leapyear;
		++baseyear;
		if (leap_year (baseyear)) {
			leapyear = 366;
		} else {
			leapyear = 365;
		}
	}
	snprintf (buff, (size_t)15, "%4.4d%3.3d", baseyear, days);
	memcpy (curr_field->data, buff, (size_t)7);
	return curr_field;
}

cob_field *
cob_intr_integer_of_date (cob_field *srcfield)
{
	int		indate;
	int		days;
	int		totaldays;
	int		month;
	int		year;
	int		baseyear;

	cob_set_exception (0);
	/* Base 1601-01-01 */
	indate = cob_get_int (srcfield);
	year = indate / 10000;
	if (year < 1601 || year > 9999) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	indate %= 10000;
	month = indate / 100;
	if (month < 1 || month > 12) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	days = indate % 100;
	if (days < 1 || days > 31) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	if (leap_year (year)) {
		if (days > leap_month_days[month]) {
			cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
			cob_alloc_set_field_uint (0);
			return curr_field;
		}
	} else {
		if (days > normal_month_days[month]) {
			cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
			cob_alloc_set_field_uint (0);
			return curr_field;
		}
	}
	totaldays = 0;
	baseyear = 1601;
	while (baseyear != year) {
		if (leap_year (baseyear)) {
			totaldays += 366;
		} else {
			totaldays += 365;
		}
		++baseyear;
	}
	if (leap_year (baseyear)) {
		totaldays += leap_days[month - 1];
	} else {
		totaldays += normal_days[month - 1];
	}
	totaldays += days;
	cob_alloc_set_field_int (totaldays);
	return curr_field;
}

cob_field *
cob_intr_integer_of_day (cob_field *srcfield)
{
	int		indate;
	int		days;
	cob_u32_t	totaldays;
	int		year;
	int		baseyear;

	cob_set_exception (0);
	/* Base 1601-01-01 */
	indate = cob_get_int (srcfield);
	year = indate / 1000;
	if (year < 1601 || year > 9999) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	days = indate % 1000;
	if (days < 1 || days > 365 + leap_year (year)) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	totaldays = 0;
	baseyear = 1601;
	while (baseyear != year) {
		if (leap_year (baseyear)) {
			totaldays += 366;
		} else {
			totaldays += 365;
		}
		++baseyear;
	}
	totaldays += days;
	cob_alloc_set_field_uint (totaldays);
	return curr_field;
}

cob_field *
cob_intr_test_date_yyyymmdd (cob_field *srcfield)
{
	int		indate;
	int		days;
	int		month;
	int		year;

	/* Base 1601-01-01 */
	indate = cob_get_int (srcfield);
	year = indate / 10000;
	if (year < 1601 || year > 9999) {
		cob_alloc_set_field_uint (1);
		return curr_field;
	}
	indate %= 10000;
	month = indate / 100;
	if (month < 1 || month > 12) {
		cob_alloc_set_field_uint (2);
		return curr_field;
	}
	days = indate % 100;
	if (days < 1 || days > 31) {
		cob_alloc_set_field_uint (3);
		return curr_field;
	}
	if (leap_year (year)) {
		if (days > leap_month_days[month]) {
			cob_alloc_set_field_uint (3);
			return curr_field;
		}
	} else {
		if (days > normal_month_days[month]) {
			cob_alloc_set_field_uint (3);
			return curr_field;
		}
	}
	cob_alloc_set_field_uint (0);
	return curr_field;
}

cob_field *
cob_intr_test_day_yyyyddd (cob_field *srcfield)
{
	int		indate;
	int		days;
	int		year;

	/* Base 1601-01-01 */
	indate = cob_get_int (srcfield);
	year = indate / 1000;
	if (year < 1601 || year > 9999) {
		cob_alloc_set_field_uint (1);
		return curr_field;
	}
	days = indate % 1000;
	if (days < 1 || days > 365 + leap_year (year)) {
		cob_alloc_set_field_uint (2);
		return curr_field;
	}
	cob_alloc_set_field_uint (0);
	return curr_field;
}

cob_field *
cob_intr_factorial (cob_field *srcfield)
{
	int		srcval;

	cob_set_exception (0);
	srcval = cob_get_int (srcfield);
	d1.scale = 0;
	if (srcval < 0) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	} else {
		mpz_fac_ui (d1.value, (cob_uli_t)srcval);
	}

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_e (void)
{
	mpf_set_ui (cob_mpft, 1UL);
	cob_mpf_exp (cob_mpft, cob_mpft);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_pi (void)
{
	mpf_set (cob_mpft, cob_pi);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_exp (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);

	cob_set_exception (0);

	if (!mpz_sgn (d1.value)) {
		/* Power is zero */
		cob_alloc_set_field_uint (1);
		return curr_field;
	}

	cob_decimal_get_mpf (cob_mpft, &d1);
	cob_mpf_exp (cob_mpft, cob_mpft);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_exp10 (cob_field *srcfield)
{
	int		sign;

	cob_decimal_set_field (&d1, srcfield);

	cob_set_exception (0);

	sign = mpz_sgn (d1.value);
	if (!sign) {
		/* Power is zero */
		cob_alloc_set_field_uint (1);
		return curr_field;
	}

	cob_trim_decimal (&d1);

	if (!d1.scale) {
		/* Integer positive/negative powers */
		if (sign < 0 && mpz_fits_sint_p (d1.value)) {
			mpz_abs (d1.value, d1.value);
			d1.scale = mpz_get_si (d1.value);
			mpz_set_ui (d1.value, 1UL);
			cob_alloc_field (&d1);
			(void)cob_decimal_get_field (&d1, curr_field, 0);
			return curr_field;
		}
		if (sign > 0 && mpz_fits_ulong_p (d1.value)) {
			mpz_ui_pow_ui (d1.value, 10UL, mpz_get_ui (d1.value));
			cob_alloc_field (&d1);
			(void)cob_decimal_get_field (&d1, curr_field, 0);
			return curr_field;
		}
	}

	mpz_set_ui (d2.value, 10UL);
	d2.scale = 0;
	cob_decimal_pow (&d2, &d1);
	cob_alloc_field (&d2);
	(void)cob_decimal_get_field (&d2, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_log (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);

	cob_set_exception (0);
	if (mpz_sgn (d1.value) <= 0) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	if (d1.scale) {
		cob_trim_decimal (&d1);
	}

	if (!d1.scale && !mpz_cmp_ui (d1.value, 1UL)) {
		/* Log (1) = 0 */
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	cob_decimal_get_mpf (cob_mpft, &d1);
	cob_mpf_log (cob_mpft, cob_mpft);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_log10 (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);

	cob_set_exception (0);
	if (mpz_sgn (d1.value) <= 0) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	if (d1.scale) {
		cob_trim_decimal (&d1);
	}

	if (!d1.scale && !mpz_cmp_ui (d1.value, 1UL)) {
		/* Log10 (1) = 0 */
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	cob_decimal_get_mpf (cob_mpft, &d1);
	cob_mpf_log10 (cob_mpft, cob_mpft);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_abs (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);
	mpz_abs (d1.value, d1.value);

	make_field_entry (srcfield);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_acos (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);

	mpz_set (d4.value, d1.value);
	mpz_set (d5.value, d1.value);
	d4.scale = d1.scale;
	d5.scale = d1.scale;
	mpz_set_si (d2.value, -1L);
	d2.scale = 0;
	mpz_set_ui (d3.value, 1UL);
	d3.scale = 0;

	cob_set_exception (0);
	if (cob_decimal_cmp (&d4, &d2) < 0 || cob_decimal_cmp (&d5, &d3) > 0) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	cob_decimal_get_mpf (cob_mpft, &d1);
	cob_mpf_acos (cob_mpft, cob_mpft);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_asin (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);

	mpz_set (d4.value, d1.value);
	mpz_set (d5.value, d1.value);
	d4.scale = d1.scale;
	d5.scale = d1.scale;
	mpz_set_si (d2.value, -1L);
	d2.scale = 0;
	mpz_set_ui (d3.value, 1UL);
	d3.scale = 0;

	cob_set_exception (0);
	if (cob_decimal_cmp (&d4, &d2) < 0 || cob_decimal_cmp (&d5, &d3) > 0) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	if (!mpz_sgn (d1.value)) {
		/* Asin (0) = 0 */
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	cob_decimal_get_mpf (cob_mpft, &d1);
	cob_mpf_asin (cob_mpft, cob_mpft);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_atan (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);

	cob_set_exception (0);

	if (!mpz_sgn (d1.value)) {
		/* Atan (0) = 0 */
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	cob_decimal_get_mpf (cob_mpft, &d1);
	cob_mpf_atan (cob_mpft, cob_mpft);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_cos (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);

	cob_set_exception (0);

	cob_decimal_get_mpf (cob_mpft, &d1);
	cob_mpf_cos (cob_mpft, cob_mpft);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_sin (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);

	cob_set_exception (0);

	cob_decimal_get_mpf (cob_mpft, &d1);
	cob_mpf_sin (cob_mpft, cob_mpft);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_tan (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);

	cob_set_exception (0);

	cob_decimal_get_mpf (cob_mpft, &d1);
	cob_mpf_tan (cob_mpft, cob_mpft);
	cob_decimal_set_mpf (&d1, cob_mpft);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_sqrt (cob_field *srcfield)
{
	cob_decimal_set_field (&d1, srcfield);

	cob_set_exception (0);
	if (mpz_sgn (d1.value) < 0) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	mpz_set_ui (d2.value, 5UL);
	d2.scale = 1;
	cob_trim_decimal (&d1);
	cob_decimal_pow (&d1, &d2);

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_numval (cob_field *srcfield)
{
	unsigned char	*final_buff;
	size_t		i;
	int		final_digits;
	int		decimal_digits;
	int		sign;
	int		decimal_seen;
	unsigned char	dec_pt;

	/* Validate source field */
	if (cob_check_numval (srcfield, NULL, 0, 0)) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	final_digits = 0;
	decimal_digits = 0;
	sign = 0;
	decimal_seen = 0;
	dec_pt = COB_MODULE_PTR->decimal_point;
	final_buff = cob_malloc (srcfield->size + 1U);

	for (i = 0; i < srcfield->size; ++i) {
		if (i < (srcfield->size - 1)) {
			if (memcmp (&srcfield->data[i], "CR", (size_t)2) == 0 ||
			    memcmp (&srcfield->data[i], "DB", (size_t)2) == 0) {
				sign = 1;
				break;
			}
		}
		if (srcfield->data[i] == ' ') {
			continue;
		}
		if (srcfield->data[i] == '+') {
			continue;
		}
		if (srcfield->data[i] == '-') {
			sign = 1;
			continue;
		}
		if (srcfield->data[i] == dec_pt) {
			decimal_seen = 1;
			continue;
		}
		if (srcfield->data[i] >= (unsigned char)'0' &&
		    srcfield->data[i] <= (unsigned char)'9') {
			if (decimal_seen) {
				decimal_digits++;
			}
			final_buff[final_digits++] = srcfield->data[i];
		}
		if (final_digits > COB_MAX_DIGITS) {
			break;
		}
	}

	if (!final_digits) {
		final_buff[0] = '0';
	}
	mpz_set_str (d1.value, (char *)final_buff, 10);
	free (final_buff);
	if (sign && mpz_sgn (d1.value)) {
		mpz_neg (d1.value, d1.value);
	}
	d1.scale = decimal_digits;
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_numval_c (cob_field *srcfield, cob_field *currency)
{
	unsigned char	*final_buff;
	unsigned char	*currency_data;
	size_t		i;
	int		decimal_digits;
	int		final_digits;
	int		sign;
	int		decimal_seen;
	unsigned char	dec_pt;
	unsigned char	cur_symb;

	/* Validate source field */
	if (cob_check_numval (srcfield, currency, 1, 0)) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	decimal_digits = 0;
	final_digits = 0;
	sign = 0;
	decimal_seen = 0;
	dec_pt = COB_MODULE_PTR->decimal_point;
	cur_symb = COB_MODULE_PTR->currency_symbol;
	final_buff = cob_malloc (srcfield->size + 1U);

	currency_data = NULL;
	if (currency) {
		if (currency->size < srcfield->size) {
			currency_data = currency->data;
		}
	}
	for (i = 0; i < srcfield->size; ++i) {
		if (i < (srcfield->size - 1)) {
			if (memcmp (&srcfield->data[i], "CR", (size_t)2) == 0 ||
			    memcmp (&srcfield->data[i], "DB", (size_t)2) == 0) {
				sign = 1;
				break;
			}
		}
		if (currency_data) {
			if (i < (srcfield->size - currency->size)) {
				if (!memcmp (&srcfield->data[i],
					     currency_data, currency->size)) {
					i += (currency->size - 1);
					continue;
				}
			}
		} else if (srcfield->data[i] == cur_symb) {
			continue;
		}
		if (srcfield->data[i] == ' ') {
			continue;
		}
		if (srcfield->data[i] == '+') {
			continue;
		}
		if (srcfield->data[i] == '-') {
			sign = 1;
			continue;
		}
		if (srcfield->data[i] == dec_pt) {
			decimal_seen = 1;
			continue;
		}
		if (srcfield->data[i] >= (unsigned char)'0' &&
		    srcfield->data[i] <= (unsigned char)'9') {
			if (decimal_seen) {
				decimal_digits++;
			}
			final_buff[final_digits++] = srcfield->data[i];
		}
		if (final_digits > COB_MAX_DIGITS) {
			break;
		}
	}

	if (!final_digits) {
		final_buff[0] = '0';
	}
	mpz_set_str (d1.value, (char *)final_buff, 10);
	free (final_buff);
	if (sign && mpz_sgn (d1.value)) {
		mpz_neg (d1.value, d1.value);
	}
	d1.scale = decimal_digits;
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_numval_f (cob_field *srcfield)
{
	unsigned char	*final_buff;
	unsigned char	*p;
	size_t		plus_minus;
	size_t		digits;
	size_t		decimal_digits;
	size_t		dec_seen;
	size_t		e_seen;
	size_t		exponent;
	size_t		e_plus_minus;
	size_t		n;
	unsigned char	dec_pt;

	/* Validate source field */
	if (cob_check_numval_f (srcfield)) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	plus_minus = 0;
	digits = 0;
	decimal_digits = 0;
	dec_seen = 0;
	e_seen = 0;
	exponent = 0;
	e_plus_minus = 0;
	dec_pt = COB_MODULE_PTR->decimal_point;

	final_buff = cob_malloc (srcfield->size + 1U);
	p = srcfield->data;
	for (n = 0; n < srcfield->size; ++n, ++p) {
		switch (*p) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (e_seen) {
				exponent *= 10;
				exponent += (*p & 0x0F);
			} else  {
				if (dec_seen) {
					decimal_digits++;
				}
				final_buff[digits++] = *p;
			}
			continue;
		case 'E':
			e_seen = 1;
			continue;
		case '-':
			if (e_seen) {
				e_plus_minus = 1;
			} else {
				plus_minus = 1;
			}
			continue;
		default:
			if (*p == dec_pt) {
				dec_seen = 1;
			}
			continue;
		}
	}

	if (!digits) {
		final_buff[0] = '0';
	}

	mpz_set_str (d1.value, (char *)final_buff, 10);
	free (final_buff);
	if (!mpz_sgn (d1.value)) {
		/* Value is zero ; sign and exponent irrelevant */
		d1.scale = 0;
		cob_alloc_field (&d1);
		(void)cob_decimal_get_field (&d1, curr_field, 0);
		return curr_field;
	}
	if (plus_minus) {
		mpz_neg (d1.value, d1.value);
	}
	if (exponent) {
		if (e_plus_minus) {
			/* Negative exponent */
			d1.scale = decimal_digits + exponent;
		} else {
			/* Positive exponent */
			if (decimal_digits >= exponent) {
				d1.scale = decimal_digits - exponent;
			} else {
				exponent -= decimal_digits;
				mpz_ui_pow_ui (cob_mexp, 10UL,
					       (cob_uli_t)exponent);
				mpz_mul (d1.value, d1.value, cob_mexp);
				d1.scale = 0;
			}
		}
	} else {
		/* No exponent */
		d1.scale = decimal_digits;
	}

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_annuity (cob_field *srcfield1, cob_field *srcfield2)
{
	int		sign;

	cob_decimal_set_field (&d1, srcfield1);
	cob_decimal_set_field (&d2, srcfield2);

	/* P1 >= 0, P2 > 0 and integer */
	sign = mpz_sgn (d1.value);
	if (sign < 0 || mpz_sgn (d2.value) <= 0 || d2.scale != 0) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	if (!sign) {
		mpz_set_ui (d1.value, 1UL);
		d1.scale = 0;
		cob_decimal_div (&d1, &d2);
		cob_alloc_field (&d1);
		(void)cob_decimal_get_field (&d1, curr_field, 0);
		return curr_field;
	}

	/* x = P1 / (1 - (1 + P1) ^ (-P2)) */
	mpz_neg (d2.value, d2.value);

	mpz_set (d3.value, d1.value);
	d3.scale = d1.scale;
	mpz_set_ui (d4.value, 1UL);
	d4.scale = 0;
	cob_decimal_add (&d3, &d4);
	cob_trim_decimal (&d3);
	cob_trim_decimal (&d2);
	cob_decimal_pow (&d3, &d2);
	mpz_set_ui (d4.value, 1UL);
	d4.scale = 0;
	cob_decimal_sub (&d4, &d3);
	cob_trim_decimal (&d4);
	cob_trim_decimal (&d1);
	cob_decimal_div (&d1, &d4);
	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_sum (const int params, ...)
{
	cob_field	*f;
	va_list		args;
	int		i;

	mpz_set_ui (d1.value, 0UL);
	d1.scale = 0;

	va_start (args, params);

	for (i = 0; i < params; ++i) {
		f = va_arg (args, cob_field *);
		cob_decimal_set_field (&d2, f);
		cob_decimal_add (&d1, &d2);
	}
	va_end (args);

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_ord_min (const int params, ...)
{
	cob_field	*f;
	cob_field	*basef;
	int		i;
	cob_u32_t	ordmin;
	va_list		args;

	va_start (args, params);

	ordmin = 1;
	basef = va_arg (args, cob_field *);
	for (i = 1; i < params; ++i) {
		f = va_arg (args, cob_field *);
		if (cob_cmp (f, basef) < 0) {
			basef = f;
			ordmin = i + 1;
		}
	}
	va_end (args);

	cob_alloc_set_field_uint (ordmin);
	return curr_field;
}

cob_field *
cob_intr_ord_max (const int params, ...)
{
	cob_field	*f;
	cob_field	*basef;
	cob_u32_t	ordmax;
	int		i;
	va_list		args;

	va_start (args, params);

	ordmax = 1;
	basef = va_arg (args, cob_field *);
	for (i = 1; i < params; ++i) {
		f = va_arg (args, cob_field *);
		if (cob_cmp (f, basef) > 0) {
			basef = f;
			ordmax = i + 1;
		}
	}
	va_end (args);

	cob_alloc_set_field_uint (ordmax);
	return curr_field;
}

cob_field *
cob_intr_min (const int params, ...)
{
	cob_field	*f;
	cob_field	*basef;
	va_list		args;
	int		i;

	va_start (args, params);

	basef = va_arg (args, cob_field *);
	for (i = 1; i < params; ++i) {
		f = va_arg (args, cob_field *);
		if (cob_cmp (f, basef) < 0) {
			basef = f;
		}
	}
	va_end (args);

	make_field_entry (basef);
	memcpy (curr_field->data, basef->data, basef->size);
	return curr_field;
}

cob_field *
cob_intr_max (const int params, ...)
{
	cob_field	*f;
	cob_field	*basef;
	va_list		args;
	int		i;

	va_start (args, params);

	basef = va_arg (args, cob_field *);
	for (i = 1; i < params; ++i) {
		f = va_arg (args, cob_field *);
		if (cob_cmp (f, basef) > 0) {
			basef = f;
		}
	}
	va_end (args);

	make_field_entry (basef);
	memcpy (curr_field->data, basef->data, basef->size);
	return curr_field;
}

cob_field *
cob_intr_midrange (const int params, ...)
{
	cob_field	*f;
	cob_field	*basemin;
	cob_field	*basemax;
	va_list		args;
	int		i;

	va_start (args, params);

	basemin = va_arg (args, cob_field *);
	basemax = basemin;
	for (i = 1; i < params; ++i) {
		f = va_arg (args, cob_field *);
		if (cob_cmp (f, basemin) < 0) {
			basemin = f;
		}
		if (cob_cmp (f, basemax) > 0) {
			basemax = f;
		}
	}
	va_end (args);

	cob_decimal_set_field (&d1, basemin);
	cob_decimal_set_field (&d2, basemax);
	cob_decimal_add (&d1, &d2);
	mpz_set_ui (d2.value, 2UL);
	d2.scale = 0;
	cob_decimal_div (&d1, &d2);

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_median (const int params, ...)
{
	cob_field	*f;
	cob_field	**field_alloc;
	va_list		args;
	int		i;

	va_start (args, params);

	f = va_arg (args, cob_field *);
	if (params == 1) {
		va_end (args);
		make_field_entry (f);
		memcpy (curr_field->data, f->data, f->size);
		return curr_field;
	}

	field_alloc = cob_malloc ((size_t)params * sizeof (cob_field *));
	field_alloc[0] = f;

	for (i = 1; i < params; ++i) {
		field_alloc[i] = va_arg (args, cob_field *);
	}
	va_end (args);

	qsort (field_alloc, (size_t)params, (size_t)sizeof (cob_field *),
	       comp_field);

	i = params / 2;
	if (params % 2) {
		f = field_alloc[i];
		make_field_entry (f);
		memcpy (curr_field->data, f->data, f->size);
	} else {
		cob_decimal_set_field (&d1, field_alloc[i-1]);
		cob_decimal_set_field (&d2, field_alloc[i]);
		cob_decimal_add (&d1, &d2);
		mpz_set_ui (d2.value, 2UL);
		d2.scale = 0;
		cob_decimal_div (&d1, &d2);
		cob_alloc_field (&d1);
		(void)cob_decimal_get_field (&d1, curr_field, 0);
	}
	free (field_alloc);
	return curr_field;
}

cob_field *
cob_intr_mean (const int params, ...)
{
	cob_field	*f;
	va_list		args;
	int		i;

	va_start (args, params);

	if (params == 1) {
		f = va_arg (args, cob_field *);
		va_end (args);
		make_field_entry (f);
		memcpy (curr_field->data, f->data, f->size);
		return curr_field;
	}

	mpz_set_ui (d1.value, 0UL);
	d1.scale = 0;

	for (i = 0; i < params; ++i) {
		f = va_arg (args, cob_field *);
		cob_decimal_set_field (&d2, f);
		cob_decimal_add (&d1, &d2);
	}
	va_end (args);

	mpz_set_ui (d2.value, (cob_uli_t)params);
	d2.scale = 0;
	cob_decimal_div (&d1, &d2);

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_mod (cob_field *srcfield1, cob_field *srcfield2)
{
	return cob_mod_or_rem (srcfield1, srcfield2, 0);
}

cob_field *
cob_intr_range (const int params, ...)
{
	cob_field	*f, *basemin, *basemax;
	va_list		args;
	int		i;

	va_start (args, params);

	basemin = va_arg (args, cob_field *);
	basemax = basemin;
	for (i = 1; i < params; ++i) {
		f = va_arg (args, cob_field *);
		if (cob_cmp (f, basemin) < 0) {
			basemin = f;
		}
		if (cob_cmp (f, basemax) > 0) {
			basemax = f;
		}
	}
	va_end (args);

	cob_decimal_set_field (&d1, basemax);
	cob_decimal_set_field (&d2, basemin);
	cob_decimal_sub (&d1, &d2);

	cob_alloc_field (&d1);
	(void)cob_decimal_get_field (&d1, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_rem (cob_field *srcfield1, cob_field *srcfield2)
{
	return cob_mod_or_rem (srcfield1, srcfield2, 1);
}

cob_field *
cob_intr_random (const int params, ...)
{
	cob_field	*f;
	va_list		args;
	cob_s64_t	val;
	int		seed;
	int		randnum;
	int		i;
	int		rexp10;
	cob_field_attr	attr;
	cob_field	field;

	COB_ATTR_INIT (COB_TYPE_NUMERIC_BINARY, 20, 9, COB_FLAG_HAVE_SIGN, NULL);
	COB_FIELD_INIT (8, NULL, &attr);
	va_start (args, params);

	if (params) {
		f = va_arg (args, cob_field *);
		seed = cob_get_int (f);
		if (seed < 0) {
			seed = 0;
		}
#ifdef	__CYGWIN__
		srandom ((unsigned int)seed);
#else
		srand ((unsigned int)seed);
#endif
	}
	va_end (args);

#ifdef	__CYGWIN__
	randnum = (int)random ();
#else
	randnum = rand ();
#endif
	rexp10 = 1;
	for (i = 0; i < 10; ++i) {
		if ((randnum / rexp10) == 0) {
			break;
		}
		rexp10 *= 10;
	}
	if (i == 0) {
		i = 1;
	}
	attr.scale = i;
	make_field_entry (&field);
	val = (cob_s64_t)randnum;
	memcpy (curr_field->data, &val, sizeof(val));
	return curr_field;
}

cob_field *
cob_intr_variance (const int params, ...)
{
	cob_field	*f;
	va_list		args;
	int		i;

	va_start (args, params);

	if (params == 1) {
		va_end (args);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	/* MEAN for all params */
	mpz_set_ui (d1.value, 0UL);
	d1.scale = 0;

	for (i = 0; i < params; ++i) {
		f = va_arg (args, cob_field *);
		cob_decimal_set_field (&d2, f);
		cob_decimal_add (&d1, &d2);
	}
	va_end (args);

	mpz_set_ui (d2.value, (cob_uli_t)params);
	d2.scale = 0;
	cob_decimal_div (&d1, &d2);

	/* Got the MEAN in d1, iterate again */

	mpz_set_ui (d4.value, 0UL);
	d4.scale = 0;

	va_start (args, params);

	for (i = 0; i < params; ++i) {
		f = va_arg (args, cob_field *);
		cob_decimal_set_field (&d2, f);
		cob_decimal_sub (&d2, &d1);
		cob_decimal_mul (&d2, &d2);
		cob_decimal_add (&d4, &d2);
	}
	va_end (args);

	mpz_set_ui (d3.value, (cob_uli_t)params);
	d3.scale = 0;
	cob_decimal_div (&d4, &d3);

	cob_alloc_field (&d4);
	(void)cob_decimal_get_field (&d4, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_standard_deviation (const int params, ...)
{
	cob_field	*f;
	va_list		args;
	int		i;

	va_start (args, params);

	if (params == 1) {
		va_end (args);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}

	/* MEAN for all params */
	mpz_set_ui (d1.value, 0UL);
	d1.scale = 0;

	for (i = 0; i < params; ++i) {
		f = va_arg (args, cob_field *);
		cob_decimal_set_field (&d2, f);
		cob_decimal_add (&d1, &d2);
	}
	va_end (args);

	mpz_set_ui (d2.value, (cob_uli_t)params);
	d2.scale = 0;
	cob_decimal_div (&d1, &d2);

	/* Got the MEAN in d1, iterate again */

	mpz_set_ui (d4.value, 0UL);
	d4.scale = 0;

	va_start (args, params);

	for (i = 0; i < params; ++i) {
		f = va_arg (args, cob_field *);
		cob_decimal_set_field (&d2, f);
		cob_decimal_sub (&d2, &d1);
		cob_decimal_mul (&d2, &d2);
		cob_decimal_add (&d4, &d2);
	}
	va_end (args);

	mpz_set_ui (d3.value, (cob_uli_t)params);
	d3.scale = 0;
	cob_decimal_div (&d4, &d3);

	/* We have the VARIANCE in d4, sqrt = STANDARD-DEVIATION */

	cob_trim_decimal (&d4);

	cob_set_exception (0);

	mpz_set_ui (d3.value, 5UL);
	d3.scale = 1;

	cob_trim_decimal (&d4);
	cob_decimal_pow (&d4, &d3);

	cob_alloc_field (&d4);
	(void)cob_decimal_get_field (&d4, curr_field, 0);

	return curr_field;
}

cob_field *
cob_intr_present_value (const int params, ...)
{
	cob_field	*f;
	va_list		args;
	int		i;

	va_start (args, params);

	f = va_arg (args, cob_field *);

	cob_decimal_set_field (&d1, f);
	mpz_set_ui (d2.value, 1UL);
	d2.scale = 0;
	cob_decimal_add (&d1, &d2);

	mpz_set_ui (d4.value, 0UL);
	d4.scale = 0;

	for (i = 1; i < params; ++i) {
		f = va_arg (args, cob_field *);
		cob_decimal_set_field (&d2, f);
		mpz_set (d3.value, d1.value);
		d3.scale = d1.scale;
		if (i > 1) {
			mpz_pow_ui (d3.value, d3.value, (cob_uli_t)i);
			d3.scale *= i;
		}
		cob_decimal_div (&d2, &d3);
		cob_decimal_add (&d4, &d2);
	}
	va_end (args);

	cob_alloc_field (&d4);
	(void)cob_decimal_get_field (&d4, curr_field, 0);
	return curr_field;
}

cob_field *
cob_intr_year_to_yyyy (const int params, ...)
{
	cob_field	*f;
	struct tm	*timeptr;
	va_list		args;
	time_t		t;
	int		year;
	int		interval;
	int		xqtyear;
	int		maxyear;

	cob_set_exception (0);
	va_start (args, params);
	f = va_arg (args, cob_field *);
	year = cob_get_int (f);
	if (params > 1) {
		f = va_arg (args, cob_field *);
		interval = cob_get_int (f);
	} else {
		interval = 50;
	}
	if (params > 2) {
		f = va_arg (args, cob_field *);
		xqtyear = cob_get_int (f);
	} else {
		t = time (NULL);
		timeptr = localtime (&t);
		xqtyear = 1900 + timeptr->tm_year;
	}
	va_end (args);

	if (year < 0 || year > 99) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	if (xqtyear < 1601 || xqtyear > 9999) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	maxyear = xqtyear + interval;
	if (maxyear < 1700 || maxyear > 9999) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	if (maxyear % 100 >= year) {
		year += 100 * (maxyear / 100);
	} else {
		year += 100 * ((maxyear / 100) - 1);
	}
	cob_alloc_set_field_int (year);
	return curr_field;
}

cob_field *
cob_intr_date_to_yyyymmdd (const int params, ...)
{
	cob_field	*f;
	struct tm	*timeptr;
	va_list		args;
	time_t		t;
	int		year;
	int		mmdd;
	int		interval;
	int		xqtyear;
	int		maxyear;

	cob_set_exception (0);
	va_start (args, params);
	f = va_arg (args, cob_field *);
	year = cob_get_int (f);
	mmdd = year % 10000;
	year /= 10000;
	if (params > 1) {
		f = va_arg (args, cob_field *);
		interval = cob_get_int (f);
	} else {
		interval = 50;
	}
	if (params > 2) {
		f = va_arg (args, cob_field *);
		xqtyear = cob_get_int (f);
	} else {
		t = time (NULL);
		timeptr = localtime (&t);
		xqtyear = 1900 + timeptr->tm_year;
	}
	va_end (args);

	if (year < 0 || year > 999999) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	if (xqtyear < 1601 || xqtyear > 9999) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	maxyear = xqtyear + interval;
	if (maxyear < 1700 || maxyear > 9999) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	if (maxyear % 100 >= year) {
		year += 100 * (maxyear / 100);
	} else {
		year += 100 * ((maxyear / 100) - 1);
	}
	year *= 10000;
	year += mmdd;
	cob_alloc_set_field_int (year);
	return curr_field;
}

cob_field *
cob_intr_day_to_yyyyddd (const int params, ...)
{
	cob_field	*f;
	struct tm	*timeptr;
	va_list		args;
	time_t		t;
	int		year;
	int		days;
	int		interval;
	int		xqtyear;
	int		maxyear;

	cob_set_exception (0);
	va_start (args, params);
	f = va_arg (args, cob_field *);
	year = cob_get_int (f);
	days = year % 1000;
	year /= 1000;
	if (params > 1) {
		f = va_arg (args, cob_field *);
		interval = cob_get_int (f);
	} else {
		interval = 50;
	}
	if (params > 2) {
		f = va_arg (args, cob_field *);
		xqtyear = cob_get_int (f);
	} else {
		t = time (NULL);
		timeptr = localtime (&t);
		xqtyear = 1900 + timeptr->tm_year;
	}
	va_end (args);

	if (year < 0 || year > 999999) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	if (xqtyear < 1601 || xqtyear > 9999) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	maxyear = xqtyear + interval;
	if (maxyear < 1700 || maxyear > 9999) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	if (maxyear % 100 >= year) {
		year += 100 * (maxyear / 100);
	} else {
		year += 100 * ((maxyear / 100) - 1);
	}
	year *= 1000;
	year += days;
	cob_alloc_set_field_int (year);
	return curr_field;
}

cob_field *
cob_intr_seconds_past_midnight (void)
{
	struct tm	*timeptr;
	time_t		t;
	int		seconds;

	t = time (NULL);
	timeptr = localtime (&t);
	/* Leap seconds ? */
	if (timeptr->tm_sec >= 60) {
		timeptr->tm_sec = 59;
	}
	seconds = (timeptr->tm_hour * 3600) + (timeptr->tm_min * 60) +
			timeptr->tm_sec;
	cob_alloc_set_field_int (seconds);
	return curr_field;
}

cob_field *
cob_intr_seconds_from_formatted_time (cob_field *format, cob_field *value)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t		n;
	cob_u32_t	seconds = 0;
	cob_u32_t	minutes = 0;
	cob_u32_t	hours = 0;
	cob_u32_t	seconds_seen = 0;
	cob_u32_t	minutes_seen = 0;
	cob_u32_t	hours_seen = 0;

	cob_set_exception (0);
	if (value->size < format->size) {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		return curr_field;
	}
	p1 = format->data;
	p2 = value->data;
	for (n = 0; n < format->size - 1; ++n, ++p1, ++p2) {
		if (!memcmp (p1, "hh", (size_t)2) && !hours_seen) {
			if (*p2 >= (unsigned char)'0' &&
			    *p2 <= (unsigned char)'9' &&
			    *(p2 + 1) >= (unsigned char)'0' &&
			    *(p2 + 1) <= (unsigned char)'9') {
				hours = ((*p2 - '0') * 10) + (*(p2 + 1) - '0');
				hours_seen = 1;
				continue;
			}
		}
		if (!memcmp (p1, "mm", (size_t)2) && !minutes_seen) {
			if (*p2 >= (unsigned char)'0' &&
			    *p2 <= (unsigned char)'9' &&
			    *(p2 + 1) >= (unsigned char)'0' &&
			    *(p2 + 1) <= (unsigned char)'9') {
				minutes = ((*p2 - '0') * 10) + (*(p2 + 1) - '0');
				minutes_seen = 1;
				continue;
			}
		}
		if (!memcmp (p1, "ss", (size_t)2) && !seconds_seen) {
			if (*p2 >= (unsigned char)'0' &&
			    *p2 <= (unsigned char)'9' &&
			    *(p2 + 1) >= (unsigned char)'0' &&
			    *(p2 + 1) <= (unsigned char)'9') {
				seconds = ((*p2 - '0') * 10) + (*(p2 + 1) - '0');
				seconds_seen = 1;
				continue;
			}
		}
	}
	if (hours_seen && minutes_seen && seconds_seen) {
		seconds += (hours * 3600) + (minutes * 60);
	} else {
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		seconds = 0;
	}
	cob_alloc_set_field_uint (seconds);
	return curr_field;
}

cob_field *
cob_intr_locale_date (const int offset, const int length,
		      cob_field *srcfield, cob_field *locale_field)
{
	cob_field	field;
#if defined(_WIN32) || defined(__CYGWIN__) || defined(HAVE_LANGINFO_CODESET)
	size_t		len;
	int		indate;
	int		days;
	int		month;
	int		year;
#ifdef	HAVE_LANGINFO_CODESET
	unsigned char	*p;
	char		*deflocale = NULL;
	struct tm	tstruct;
	char		buff2[128];
#else
	unsigned char	*p;
	LCID		localeid = LOCALE_USER_DEFAULT;
	SYSTEMTIME	syst;
#endif
	char		buff[128];
	char		locale_buff[COB_SMALL_BUFF];
#endif

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	cob_set_exception (0);

#if defined(_WIN32) || defined(__CYGWIN__) || defined(HAVE_LANGINFO_CODESET)
	if (COB_FIELD_IS_NUMERIC (srcfield)) {
		indate = cob_get_int (srcfield);
	} else {
		if (srcfield->size < 8) {
			goto derror;
		}
		p = srcfield->data;
		indate = 0;
		for (len = 0; len < 8; ++len, ++p) {
			if (isdigit (*p)) {
				indate *= 10;
				indate += (*p - '0');
			} else {
				goto derror;
			}
		}
	}
	year = indate / 10000;
	if (year < 1601 || year > 9999) {
		goto derror;
	}
	indate %= 10000;
	month = indate / 100;
	if (month < 1 || month > 12) {
		goto derror;
	}
	days = indate % 100;
	if (days < 1 || days > 31) {
		goto derror;
	}
	if (leap_year (year)) {
		if (days > leap_month_days[month]) {
			goto derror;
		}
	} else {
		if (days > normal_month_days[month]) {
			goto derror;
		}
	}
#ifdef	HAVE_LANGINFO_CODESET
	month--;

	memset ((void *)&tstruct, 0, sizeof(struct tm));
	tstruct.tm_year = year - 1900;
	tstruct.tm_mon = month;
	tstruct.tm_mday = days;
	if (locale_field) {
		if (locale_field->size >= COB_SMALL_BUFF) {
			goto derror;
		}
		cob_field_to_string (locale_field, locale_buff,
				     (size_t)COB_SMALL_MAX);
		deflocale = locale_buff;
		(void) setlocale (LC_TIME, deflocale);
	}
	memset (buff2, 0, sizeof(buff2));
	snprintf(buff2, sizeof(buff2) - 1, "%s", nl_langinfo(D_FMT));
	if (deflocale) {
		(void) setlocale (LC_ALL, cobglobptr->cob_locale);
	}
	strftime (buff, sizeof(buff), buff2, &tstruct);
#else
	memset ((void *)&syst, 0, sizeof(syst));
	syst.wYear = year;
	syst.wMonth = month;
	syst.wDay = days;
	if (locale_field) {
		if (locale_field->size >= COB_SMALL_BUFF) {
			goto derror;
		}
		cob_field_to_string (locale_field, locale_buff,
						COB_SMALL_MAX);
		for (p = (unsigned char *)locale_buff; *p; ++p) {
			if (isalnum(*p) || *p == '_') {
				continue;
			}
			break;
		}
		*p = 0;
		for (len = 0; len < WINLOCSIZE; ++len) {
			if (!strcmp(locale_buff, wintable[len].winlocalename)) {
				localeid = wintable[len].winlocaleid;
				break;
			}
		}
		if (len == WINLOCSIZE) {
			goto derror;
		}
	}
	if (!GetDateFormat (localeid, DATE_SHORTDATE, &syst, NULL, buff, sizeof(buff))) {
		goto derror;
	}
#endif
	len = strlen (buff);
	field.size = len;
	make_field_entry (&field);
	memcpy (curr_field->data, buff, len);
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	return curr_field;
derror:
#endif
	field.size = 10;
	make_field_entry (&field);
	memset (curr_field->data, ' ', (size_t)10);
	cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
	return curr_field;
}

cob_field *
cob_intr_locale_time (const int offset, const int length,
		      cob_field *srcfield, cob_field *locale_field)
{
	cob_field	field;
#if defined(_WIN32) || defined(__CYGWIN__) || defined(HAVE_LANGINFO_CODESET)
	size_t		len;
	int		indate;
	int		hours;
	int		minutes;
	int		seconds;
#ifdef	HAVE_LANGINFO_CODESET
	unsigned char	*p;
	char		*deflocale = NULL;
	struct tm	tstruct;
	char		buff2[128];
#else
	unsigned char	*p;
	LCID		localeid = LOCALE_USER_DEFAULT;
	SYSTEMTIME	syst;
#endif
	char		buff[128];
	char		locale_buff[COB_SMALL_BUFF];
#endif

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	cob_set_exception (0);

#if defined(_WIN32) || defined(__CYGWIN__) || defined(HAVE_LANGINFO_CODESET)
	if (COB_FIELD_IS_NUMERIC (srcfield)) {
		indate = cob_get_int (srcfield);
	} else {
		if (srcfield->size < 6) {
			goto derror;
		}
		p = srcfield->data;
		indate = 0;
		for (len = 0; len < 6; ++len, ++p) {
			if (isdigit (*p)) {
				indate *= 10;
				indate += (*p - '0');
			} else {
				goto derror;
			}
		}
	}
	hours = indate / 10000;
	if (hours < 0 || hours > 24) {
		goto derror;
	}
	indate %= 10000;
	minutes = indate / 100;
	if (minutes < 0 || minutes > 59) {
		goto derror;
	}
	seconds = indate % 100;
	if (seconds < 0 || seconds > 59) {
		goto derror;
	}

#ifdef	HAVE_LANGINFO_CODESET
	memset ((void *)&tstruct, 0, sizeof(struct tm));
	tstruct.tm_hour = hours;
	tstruct.tm_min = minutes;
	tstruct.tm_sec = seconds;
	if (locale_field) {
		if (locale_field->size >= COB_SMALL_BUFF) {
			goto derror;
		}
		cob_field_to_string (locale_field, locale_buff,
				     (size_t)COB_SMALL_MAX);
		deflocale = locale_buff;
		(void) setlocale (LC_TIME, deflocale);
	}
	memset (buff2, 0, sizeof(buff2));
	snprintf(buff2, sizeof(buff2) - 1, "%s", nl_langinfo(T_FMT));
	if (deflocale) {
		(void) setlocale (LC_ALL, cobglobptr->cob_locale);
	}
	strftime (buff, sizeof(buff), buff2, &tstruct);
#else
	memset ((void *)&syst, 0, sizeof(syst));
	syst.wHour = hours;
	syst.wMinute = minutes;
	syst.wSecond = seconds;
	if (locale_field) {
		if (locale_field->size >= COB_SMALL_BUFF) {
			goto derror;
		}
		cob_field_to_string (locale_field, locale_buff,
						COB_SMALL_MAX);
		for (p = (unsigned char *)locale_buff; *p; ++p) {
			if (isalnum((int)*p) || *p == '_') {
				continue;
			}
			break;
		}
		*p = 0;
		for (len = 0; len < WINLOCSIZE; ++len) {
			if (!strcmp(locale_buff, wintable[len].winlocalename)) {
				localeid = wintable[len].winlocaleid;
				break;
			}
		}
		if (len == WINLOCSIZE) {
			goto derror;
		}
	}
	if (!GetTimeFormat (localeid, LOCALE_NOUSEROVERRIDE, &syst, NULL, buff, sizeof(buff))) {

		goto derror;
	}
#endif
	len = strlen (buff);
	field.size = len;
	make_field_entry (&field);
	memcpy (curr_field->data, buff, len);
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	return curr_field;
derror:
#endif
	field.size = 10;
	make_field_entry (&field);
	memset (curr_field->data, ' ', (size_t)10);
	cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
	return curr_field;
}

cob_field *
cob_intr_lcl_time_from_secs (const int offset, const int length,
			     cob_field *srcfield, cob_field *locale_field)
{
	cob_field	field;
#if defined(_WIN32) || defined(__CYGWIN__) || defined(HAVE_LANGINFO_CODESET)
	size_t		len;
	int		indate;
	int		hours;
	int		minutes;
	int		seconds;
#ifdef	HAVE_LANGINFO_CODESET
	char		*deflocale = NULL;
	struct tm	tstruct;
	char		buff2[128];
#else
	unsigned char	*p;
	LCID		localeid = LOCALE_USER_DEFAULT;
	SYSTEMTIME	syst;
#endif
	char		buff[128];
	char		locale_buff[COB_SMALL_BUFF];
#endif

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	cob_set_exception (0);

#if defined(_WIN32) || defined(__CYGWIN__) || defined(HAVE_LANGINFO_CODESET)
	if (COB_FIELD_IS_NUMERIC (srcfield)) {
		indate = cob_get_int (srcfield);
	} else {
		goto derror;
	}
	if (indate > 86400) {
		goto derror;
	}
	hours = indate / 3600;
	indate %= 3600;
	minutes = indate / 60;
	seconds = indate % 60;

#ifdef	HAVE_LANGINFO_CODESET
	memset ((void *)&tstruct, 0, sizeof(struct tm));
	tstruct.tm_hour = hours;
	tstruct.tm_min = minutes;
	tstruct.tm_sec = seconds;
	if (locale_field) {
		if (locale_field->size >= COB_SMALL_BUFF) {
			goto derror;
		}
		cob_field_to_string (locale_field, locale_buff,
				     (size_t)COB_SMALL_MAX);
		deflocale = locale_buff;
		(void) setlocale (LC_TIME, deflocale);
	}
	memset (buff2, 0, sizeof(buff2));
	snprintf(buff2, sizeof(buff2) - 1, "%s", nl_langinfo(T_FMT));
	if (deflocale) {
		(void) setlocale (LC_ALL, cobglobptr->cob_locale);
	}
	strftime (buff, sizeof(buff), buff2, &tstruct);
#else
	memset ((void *)&syst, 0, sizeof(syst));
	syst.wHour = hours;
	syst.wMinute = minutes;
	syst.wSecond = seconds;
	if (locale_field) {
		if (locale_field->size >= COB_SMALL_BUFF) {
			goto derror;
		}
		cob_field_to_string (locale_field, locale_buff,
						COB_SMALL_MAX);
		for (p = (unsigned char *)locale_buff; *p; ++p) {
			if (isalnum(*p) || *p == '_') {
				continue;
			}
			break;
		}
		*p = 0;
		for (len = 0; len < WINLOCSIZE; ++len) {
			if (!strcmp(locale_buff, wintable[len].winlocalename)) {
				localeid = wintable[len].winlocaleid;
				break;
			}
		}
		if (len == WINLOCSIZE) {
			goto derror;
		}
	}
	if (!GetTimeFormat (localeid, LOCALE_NOUSEROVERRIDE, &syst, NULL, buff, sizeof(buff))) {

		goto derror;
	}
#endif
	len = strlen (buff);
	field.size = len;
	make_field_entry (&field);
	memcpy (curr_field->data, buff, len);
	if (unlikely(offset > 0)) {
		calc_ref_mod (curr_field, offset, length);
	}
	return curr_field;
derror:
#endif
	field.size = 10;
	make_field_entry (&field);
	memset (curr_field->data, ' ', (size_t)10);
	cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
	return curr_field;
}

cob_field *
cob_intr_mon_decimal_point (void)
{
#ifdef	HAVE_LOCALECONV
	struct lconv	*p;
	size_t		size;
#endif
	cob_field	field;

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	cob_set_exception (0);

#ifdef	HAVE_LOCALECONV
	p = localeconv ();
	size = strlen (p->mon_decimal_point);
	if (size) {
		field.size = size;
	} else {
		field.size = 1;
	}
	make_field_entry (&field);
	if (size) {
		memcpy (curr_field->data, p->mon_decimal_point, size);
	} else {
		curr_field->size = 0;
		curr_field->data[0] = 0;
	}
#else
	field.size = 1;
	make_field_entry (&field);
	curr_field->data[0] = COB_MODULE_PTR->decimal_point;
#endif
	return curr_field;
}

cob_field *
cob_intr_num_decimal_point (void)
{
#ifdef	HAVE_LOCALECONV
	struct lconv	*p;
	size_t		size;
#endif
	cob_field	field;

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	cob_set_exception (0);

#ifdef	HAVE_LOCALECONV
	p = localeconv ();
	size = strlen (p->decimal_point);
	if (size) {
		field.size = size;
	} else {
		field.size = 1;
	}
	make_field_entry (&field);
	if (size) {
		memcpy (curr_field->data, p->decimal_point, size);
	} else {
		curr_field->size = 0;
		curr_field->data[0] = 0;
	}
#else
	field.size = 1;
	make_field_entry (&field);
	curr_field->data[0] = COB_MODULE_PTR->decimal_point;
#endif
	return curr_field;
}

cob_field *
cob_intr_mon_thousands_sep (void)
{
#ifdef	HAVE_LOCALECONV
	struct lconv	*p;
	size_t		size;
#endif
	cob_field	field;

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	cob_set_exception (0);

#ifdef	HAVE_LOCALECONV
	p = localeconv ();
	size = strlen (p->mon_thousands_sep);
	if (size) {
		field.size = size;
	} else {
		field.size = 1;
	}
	make_field_entry (&field);
	if (size) {
		memcpy (curr_field->data, p->mon_thousands_sep, size);
	} else {
		curr_field->size = 0;
		curr_field->data[0] = 0;
	}
#else
	field.size = 1;
	make_field_entry (&field);
	curr_field->data[0] = COB_MODULE_PTR->decimal_point;
#endif
	return curr_field;
}

cob_field *
cob_intr_num_thousands_sep (void)
{
#ifdef	HAVE_LOCALECONV
	struct lconv	*p;
	size_t		size;
#endif
	cob_field	field;

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	cob_set_exception (0);

#ifdef	HAVE_LOCALECONV
	p = localeconv ();
	size = strlen (p->thousands_sep);
	if (size) {
		field.size = size;
	} else {
		field.size = 1;
	}
	make_field_entry (&field);
	if (size) {
		memcpy (curr_field->data, p->thousands_sep, size);
	} else {
		curr_field->size = 0;
		curr_field->data[0] = 0;
	}
#else
	field.size = 1;
	make_field_entry (&field);
	curr_field->data[0] = COB_MODULE_PTR->decimal_point;
#endif
	return curr_field;
}

cob_field *
cob_intr_currency_symbol (void)
{
#ifdef	HAVE_LOCALECONV
	struct lconv	*p;
	size_t		size;
#endif
	cob_field	field;

	COB_FIELD_INIT (0, NULL, &const_alpha_attr);
	cob_set_exception (0);

#ifdef	HAVE_LOCALECONV
	p = localeconv ();
	size = strlen (p->currency_symbol);
	if (size) {
		field.size = size;
	} else {
		field.size = 1;
	}
	make_field_entry (&field);
	if (size) {
		memcpy (curr_field->data, p->currency_symbol, size);
	} else {
		curr_field->size = 0;
		curr_field->data[0] = 0;
	}
#else
	field.size = 1;
	make_field_entry (&field);
	curr_field->data[0] = COB_MODULE_PTR->currency_symbol;
#endif
	return curr_field;
}

cob_field *
cob_intr_test_numval (cob_field *srcfield)
{
	cob_alloc_set_field_int (cob_check_numval (srcfield, NULL, 0, 0));
	return curr_field;
}

cob_field *
cob_intr_test_numval_c (cob_field *srcfield, cob_field *currency)
{
	cob_alloc_set_field_int (cob_check_numval (srcfield, currency, 1, 0));
	return curr_field;
}

cob_field *
cob_intr_test_numval_f (cob_field *srcfield)
{
	cob_alloc_set_field_int (cob_check_numval_f (srcfield));
	return curr_field;
}

cob_field *
cob_intr_lowest_algebraic (cob_field *srcfield)
{
	cob_uli_t	expo;
	cob_field	field;

	switch (COB_FIELD_TYPE (srcfield)) {
	case COB_TYPE_ALPHANUMERIC:
	case COB_TYPE_NATIONAL:
		COB_FIELD_INIT (COB_FIELD_SIZE (srcfield), NULL, &const_alpha_attr);
		make_field_entry (&field);
		break;

	case COB_TYPE_ALPHANUMERIC_EDITED:
	case COB_TYPE_NATIONAL_EDITED:
		COB_FIELD_INIT (COB_FIELD_DIGITS (srcfield), NULL, &const_alpha_attr);
		make_field_entry (&field);
		break;

	case COB_TYPE_NUMERIC_BINARY:
		if (!COB_FIELD_HAVE_SIGN (srcfield)) {
			cob_alloc_set_field_uint (0);
			break;
		}
		if (COB_FIELD_REAL_BINARY (srcfield) ||
		    !COB_FIELD_BINARY_TRUNC (srcfield)) {
			expo = (cob_uli_t)((COB_FIELD_SIZE (srcfield) * 8U) - 1U);
			mpz_ui_pow_ui (d1.value, 2UL, expo);
			mpz_neg (d1.value, d1.value);
			d1.scale = COB_FIELD_SCALE (srcfield);
			cob_alloc_field (&d1);
			(void)cob_decimal_get_field (&d1, curr_field, 0);
			break;
		}
		expo = (cob_uli_t)COB_FIELD_DIGITS (srcfield);
		mpz_ui_pow_ui (d1.value, 10UL, expo);
		mpz_sub_ui (d1.value, d1.value, 1UL);
		mpz_neg (d1.value, d1.value);
		d1.scale = COB_FIELD_SCALE (srcfield);
		cob_alloc_field (&d1);
		(void)cob_decimal_get_field (&d1, curr_field, 0);
		break;

	case COB_TYPE_NUMERIC_FLOAT:
	case COB_TYPE_NUMERIC_DOUBLE:
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		break;

	case COB_TYPE_NUMERIC_DISPLAY:
	case COB_TYPE_NUMERIC_PACKED:
	case COB_TYPE_NUMERIC_EDITED:
		if (!COB_FIELD_HAVE_SIGN (srcfield)) {
			cob_alloc_set_field_uint (0);
			break;
		}
		expo = (cob_uli_t)COB_FIELD_DIGITS (srcfield);
		mpz_ui_pow_ui (d1.value, 10UL, expo);
		mpz_sub_ui (d1.value, d1.value, 1UL);
		mpz_neg (d1.value, d1.value);
		d1.scale = COB_FIELD_SCALE (srcfield);
		cob_alloc_field (&d1);
		(void)cob_decimal_get_field (&d1, curr_field, 0);
		break;
	default:
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		break;
	}
	return curr_field;
}

cob_field *
cob_intr_highest_algebraic (cob_field *srcfield)
{
	cob_uli_t	expo;
	size_t		size;
	cob_field	field;

	switch (COB_FIELD_TYPE (srcfield)) {
	case COB_TYPE_ALPHANUMERIC:
	case COB_TYPE_NATIONAL:
		size = COB_FIELD_SIZE (srcfield);
		COB_FIELD_INIT (size, NULL, &const_alpha_attr);
		make_field_entry (&field);
		memset (curr_field->data, 255, size);
		break;

	case COB_TYPE_ALPHANUMERIC_EDITED:
	case COB_TYPE_NATIONAL_EDITED:
		size = COB_FIELD_DIGITS (srcfield);
		COB_FIELD_INIT (size, NULL, &const_alpha_attr);
		make_field_entry (&field);
		memset (curr_field->data, 255, size);
		break;

	case COB_TYPE_NUMERIC_BINARY:
		if (COB_FIELD_REAL_BINARY (srcfield) ||
		    !COB_FIELD_BINARY_TRUNC (srcfield)) {
			if (!COB_FIELD_HAVE_SIGN (srcfield)) {
				expo = COB_FIELD_SIZE (srcfield) * 8U;
			} else {
				expo = (COB_FIELD_SIZE (srcfield) * 8U) - 1U;
			}
			mpz_ui_pow_ui (d1.value, 2UL, expo);
			mpz_sub_ui (d1.value, d1.value, 1UL);
			d1.scale = COB_FIELD_SCALE (srcfield);
			cob_alloc_field (&d1);
			(void)cob_decimal_get_field (&d1, curr_field, 0);
			break;
		}
		expo = (cob_uli_t)COB_FIELD_DIGITS (srcfield);
		mpz_ui_pow_ui (d1.value, 10UL, expo);
		mpz_sub_ui (d1.value, d1.value, 1UL);
		d1.scale = COB_FIELD_SCALE (srcfield);
		cob_alloc_field (&d1);
		(void)cob_decimal_get_field (&d1, curr_field, 0);
		break;

	case COB_TYPE_NUMERIC_FLOAT:
	case COB_TYPE_NUMERIC_DOUBLE:
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		break;

	case COB_TYPE_NUMERIC_DISPLAY:
	case COB_TYPE_NUMERIC_PACKED:
	case COB_TYPE_NUMERIC_EDITED:
		expo = (cob_uli_t)COB_FIELD_DIGITS (srcfield);
		mpz_ui_pow_ui (d1.value, 10UL, expo);
		mpz_sub_ui (d1.value, d1.value, 1UL);
		d1.scale = COB_FIELD_SCALE (srcfield);
		cob_alloc_field (&d1);
		(void)cob_decimal_get_field (&d1, curr_field, 0);
		break;
	default:
		cob_set_exception (COB_EC_ARGUMENT_FUNCTION);
		cob_alloc_set_field_uint (0);
		break;
	}
	return curr_field;
}

cob_field *
cob_intr_locale_compare (const int params, ...)
{
	cob_field	*f1;
	cob_field	*f2;
	cob_field	*locale_field;
#ifdef	HAVE_STRCOLL
	unsigned char	*p;
	unsigned char	*p1;
	unsigned char	*p2;
	char		*deflocale;
	size_t		size;
	size_t		size2;
	int		ret;
#endif
	cob_field	field;
	va_list		args;

	cob_set_exception (0);
	va_start (args, params);
	f1 = va_arg (args, cob_field *);
	f2 = va_arg (args, cob_field *);
	if (params > 2) {
		locale_field = va_arg (args, cob_field *);
	} else {
		locale_field = NULL;
	}
	va_end (args);

	COB_FIELD_INIT (1, NULL, &const_alpha_attr);
	make_field_entry (&field);

#ifdef	HAVE_STRCOLL
	deflocale = NULL;

	size = f1->size;
	size2 = size;
	for (p = f1->data + size - 1U; p != f1->data; --p) {
		if (*p != ' ') {
			break;
		}
		size2--;
	}
	p1 = cob_malloc (size2 + 1U);
	memcpy (p1, f1->data, size2);

	size = f2->size;
	size2 = size;
	for (p = f2->data + size - 1U; p != f2->data; --p) {
		if (*p != ' ') {
			break;
		}
		size2--;
	}
	p2 = cob_malloc (size2 + 1U);
	memcpy (p2, f2->data, size2);

	if (locale_field) {
		if (!locale_field->size) {
			goto derror;
		}
#ifdef	HAVE_SETLOCALE
		deflocale = cob_malloc (locale_field->size + 1U);
		cob_field_to_string (locale_field, deflocale,
				     (size_t)(locale_field->size + 1U));
		(void) setlocale (LC_COLLATE, deflocale);
#else
		goto derror;
#endif
	}

	ret = strcoll ((char *)p1, (char *)p2);
	if (ret < 0) {
		curr_field->data[0] = '<';
	} else if (ret > 0) {
		curr_field->data[0] = '>';
	} else {
		curr_field->data[0] = '=';
	}
	free (p1);
	free (p2);

#ifdef	HAVE_SETLOCALE
	if (deflocale) {
		(void) setlocale (LC_ALL, cobglobptr->cob_locale);
		free (deflocale);
	}
#endif

	return curr_field;
derror:
#endif
	curr_field->data[0] = ' ';
	cob_set_exception (COB_EC_ARGUMENT_FUNCTION);

	return curr_field;
}

/* RXWRXW - To be implemented */

cob_field *
cob_intr_boolean_of_integer (cob_field *f1, cob_field *f2)
{
	COB_UNUSED (f1);
	COB_UNUSED (f2);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_char_national (cob_field *srcfield)
{
	COB_UNUSED (srcfield);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_display_of (const int offset, const int length,
		     const int params, ...)
{
	COB_UNUSED (offset);
	COB_UNUSED (length);
	COB_UNUSED (params);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_exception_file_n (void)
{
	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_exception_location_n (void)
{
	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_formatted_current_date (const int offset, const int length,
				 cob_field *srcfield)
{
	COB_UNUSED (offset);
	COB_UNUSED (length);
	COB_UNUSED (srcfield);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_formatted_date (const int offset, const int length,
			 cob_field *f1, cob_field *f2)
{
	COB_UNUSED (offset);
	COB_UNUSED (length);
	COB_UNUSED (f1);
	COB_UNUSED (f2);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_formatted_datetime (const int offset, const int length,
			     const int params, ...)
{
	COB_UNUSED (offset);
	COB_UNUSED (length);
	COB_UNUSED (params);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_formatted_time (const int offset, const int length,
			 const int params, ...)
{
	COB_UNUSED (offset);
	COB_UNUSED (length);
	COB_UNUSED (params);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_integer_of_boolean (cob_field *srcfield)
{
	COB_UNUSED (srcfield);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_integer_of_formatted_date (cob_field *f1, cob_field *f2)
{
	COB_UNUSED (f1);
	COB_UNUSED (f2);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_national_of (const int offset, const int length, const int params, ...)
{
	COB_UNUSED (offset);
	COB_UNUSED (length);
	COB_UNUSED (params);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_standard_compare (const int params, ...)
{
	COB_UNUSED (params);

	cob_fatal_error (COB_FERROR_FUNCTION);
}

cob_field *
cob_intr_test_formatted_datetime (cob_field *f1, cob_field *f2)
{
	COB_UNUSED (f1);
	COB_UNUSED (f2);

	cob_fatal_error (COB_FERROR_FUNCTION);
}


/* Initialization/exit routines */

void
cob_exit_intrinsic (void)
{
	struct calc_struct	*calc_temp;
	cob_u32_t		i;

	mpf_clear (cob_log_half);
	mpf_clear (cob_sqrt_two);
	mpf_clear (cob_pi);

	mpf_clear (cob_mpft_get);
	mpf_clear (cob_mpft2);
	mpf_clear (cob_mpft);

	mpz_clear (d5.value);
	mpz_clear (d4.value);
	mpz_clear (d3.value);
	mpz_clear (d2.value);
	mpz_clear (d1.value);

	mpz_clear (cob_mpzt);
	mpz_clear (cob_mexp);

	calc_temp = calc_base;
	for (i = 0; i < COB_DEPTH_LEVEL; ++i, ++calc_temp) {
		if (calc_temp->calc_field.data) {
			free (calc_temp->calc_field.data);
		}
	}
	free (calc_base);
}

void
cob_init_intrinsic (cob_global *lptr)
{
	struct calc_struct	*calc_temp;
	cob_u32_t		i;

	cobglobptr = lptr;

	move_field = NULL;
	curr_entry = 0;
	curr_field = NULL;
	calc_base = cob_malloc (COB_DEPTH_LEVEL * sizeof(struct calc_struct));
	calc_temp = calc_base;
	for (i = 0; i < COB_DEPTH_LEVEL; ++i, ++calc_temp) {
		calc_temp->calc_field.data = cob_malloc ((size_t)256);
		calc_temp->calc_field.size = 256;
		calc_temp->calc_size = 256;
	}

	mpz_init2 (cob_mexp, COB_MPZ_DEF);
	mpz_init2 (cob_mpzt, COB_MPZ_DEF);
	mpz_init2 (d1.value, 1536UL);
	d1.scale = 0;
	mpz_init2 (d2.value, 1536UL);
	d2.scale = 0;
	mpz_init2 (d3.value, 1536UL);
	d3.scale = 0;
	mpz_init2 (d4.value, 1536UL);
	d4.scale = 0;
	mpz_init2 (d5.value, 1536UL);
	d5.scale = 0;

	mpf_init2 (cob_mpft, COB_MPF_PREC);
	mpf_init2 (cob_mpft2, COB_MPF_PREC);
	mpf_init2 (cob_mpft_get, COB_MPF_PREC);

	mpf_init2 (cob_pi, COB_PI_LEN);
	mpf_set_str (cob_pi, cob_pi_str, 10);

	mpf_init2 (cob_sqrt_two, COB_SQRT_TWO_LEN);
	mpf_set_str (cob_sqrt_two, cob_sqrt_two_str, 10);

	mpf_init2 (cob_log_half, COB_LOG_HALF_LEN);
	mpf_set_str (cob_log_half, cob_log_half_str, 10);
}
