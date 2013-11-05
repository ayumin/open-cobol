#
# gnu-cobol-cpp/tests/cobol85/report.pl
#
# Copyright (C) 2001,2002,2003,2004,2005,2006,2007 Keisuke Nishida
# Copyright (C) 2007-2012 Roger While
#
# This file is part of GNU Cobol C++.
#
# The GNU Cobol C++ compiler is free software: you can redistribute it
# and/or modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# GNU Cobol C++ is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Cobol C++.  If not, see <http://www.gnu.org/licenses/>.

$SIG{INT} = sub { die "\nInterrupted\n" };
$SIG{QUIT} = sub { die "\nInterrupted\n" };
$SIG{PIPE} = sub { die "\nInterrupted\n" };
$SIG{TERM} = sub { die "\nInterrupted\n" };

my $opt = shift;

my $compile;
my $compile_module;

if ($opt) {
	$compile = "cobc -std=cobol85 -x $opt";
# 	$compile = "cobc -std=cobol85 $opt";
	$compile_module = "cobc -std=cobol85 -m $opt";
} else {
	$compile = "cobc -std=cobol85 -x";
# 	$compile = "cobc -std=cobol85";
	$compile_module = "cobc -std=cobol85 -m";
}

my $num_progs = 0;
my $test_skipped = 0;
my $compile_error = 0;
my $execute_error = 0;

my $total_all = 0;
my $total_pass = 0;
my $total_fail = 0;
my $total_deleted = 0;
my $total_inspect = 0;
my $total_ok = 0;
my $ret = 0;
my $db103m = 0;

$ENV{"COB_SWITCH_1"} = "ON";
$ENV{"COB_SWITCH_2"} = "OFF";

$ENV{"COB_DISABLE_WARNINGS"} = "Y";

# DB103M should be executed twice with differing
# runtime DEBUG switch.
# Dealt with lower down in the code

# NC113M does not adhere to the test convention
# Dealt with lower down in the code

# Skip programs using COMMUNICATION
$skip{DB205A} = 1;
$skip{DB304M} = 1;

# Skip DB203A if no ISAM configured
if ($ENV{'COB_HAS_ISAM'} eq "no") {
	$skip{DB203A} = 1;
}

# Compile only programs
$componly{OBNC1M} = 1;

$componly{NC302M} = 1;
$componly{NC303M} = 1;
$componly{NC401M} = 1;

$componly{RL301M} = 1;
$componly{RL302M} = 1;
$componly{RL401M} = 1;

$componly{SM301M} = 1;
$componly{SM401M} = 1;

$componly{IC401M} = 1;

$componly{IF401M} = 1;
$componly{IF403M} = 1;

$componly{IX301M} = 1;
$componly{IX302M} = 1;
$componly{IX401M} = 1;

$componly{SG302M} = 1;
$componly{SG303M} = 1;
$componly{SG401M} = 1;

$componly{SQ302M} = 1;
$componly{SQ303M} = 1;
$componly{SQ401M} = 1;

$componly{ST301M} = 1;

$componly{RW301M} = 1;
$componly{RW302M} = 1;

# Programs that do not produce any meaningful test results
# However they must execute successfully

$nooutput{NC110M} = 1;
$nooutput{NC214M} = 1;
$nooutput{OBSQ3A} = 1;
$nooutput{ST102A} = 1;
$nooutput{ST109A} = 1;
$nooutput{ST110A} = 1;
$nooutput{ST112M} = 1;
$nooutput{ST113M} = 1;
$nooutput{ST115A} = 1;
$nooutput{ST116A} = 1;
$nooutput{ST120A} = 1;
$nooutput{ST122A} = 1;
$nooutput{ST123A} = 1;
$nooutput{DB301M} = 1;
$nooutput{DB302M} = 1;
$nooutput{DB303M} = 1;
$nooutput{DB305M} = 1;
$nooutput{IF402M} = 1;


open (LOG, "> report.txt") or die;
print LOG "Filename    total pass fail deleted inspect\n";
print LOG "--------    ----- ---- ---- ------- -------\n";

foreach $in (glob("lib/*.CBL")) {
	print "$compile_module $in\n";
	$ret = system ("trap 'exit 77' INT QUIT TERM PIPE; $compile_module $in");
	if ($ret != 0) {
		if (($ret >> 8) == 77) {
			die "Interrupted\n";
		}
		print "Unexpected status $ret for module $in\n";
	}
}

foreach $in (sort (glob("*.{CBL,SUB}"))) {
	my $exe = $in;
	my $cmd;
	my $subt;

	$exe =~ s/\.CBL//;
	$exe =~ s/\.SUB//;
	if (-e "./$exe.DAT") {
		$cmd = "./$exe < $exe.DAT";
# 		$cmd = "cobcrun $exe < $exe.DAT";
	} else {
		$cmd = "./$exe";
#		$cmd = "cobcrun $exe";
	}
	printf LOG "%-12s", $in;
	if ($skip{$exe}) {
		$test_skipped++;
		print LOG "  ----- test skipped -----\n";
		next;
	}
	$num_progs++;
	$copy = ($exe =~ /^SM/) ? "-I ../copy" : "";
	if ($componly{$exe}) {
		print "$compile $copy $in\n";
	} else {
		print "$compile $copy $in && $cmd\n";
	}
	if ($in eq "SM206A.CBL") {
		$ret = system ("trap 'exit 77' INT QUIT TERM PIPE; $compile -fdebugging-line $copy $in");
	} elsif ($in eq "NC127A.CBL") {
		$ret = system ("trap 'exit 77' INT QUIT TERM PIPE; $compile -ffold-call=upper $copy $in");
	} else {
		$ret = system ("trap 'exit 77' INT QUIT TERM PIPE; $compile $copy $in");
	}
	if ($ret != 0) {
		if (($ret >> 8) == 77) {
			die "Interrupted\n";
		}
		$compile_error++;
		print LOG "  ===== compile error =====\n";
		next;
	}
	if ($componly{$exe}) {
		printf LOG ("    1    1    0       0       0 OK\n");
		$total_all++;
		$total_pass++;
		$total_ok++;
		next;
	}
	if ($in =~ /\.CBL/) {
		if ($ENV{'DB_HOME'}) {
			$ret = system ("trap 'exit 77' INT QUIT TERM PIPE; rm -f XXXXX*; rm -f $ENV{'DB_HOME'}/XXXXX*");
		} else {
			$ret = system ("trap 'exit 77' INT QUIT TERM PIPE; rm -f XXXXX*");
		}
		if (($ret >> 8) == 77) {
			die "Interrupted\n";
		}
	}
	$subt = substr($exe, 0, 2);
	if ($exe eq "DB102A") {
		$ENV{"COB_SET_DEBUG"} = "N";
	} elsif ($subt eq "DB") {
		$ENV{"COB_SET_DEBUG"} = "Y";
	} else {
		$ENV{"COB_SET_DEBUG"} = "N";
	}
	if ($subt eq "RW") {
		$ENV{"DD_XXXXX049"} = "$exe.rep";
	}
testrepeat:
	$ret = system ("trap 'exit 77' INT QUIT TERM PIPE; $cmd > $exe.out");
	if ($ret != 0) {
		if (($ret >> 8) == 77) {
			die "Interrupted\n";
		}
		$execute_error++;
		print LOG "***** execute error *****\n";
		next;
	}
	my $total = 0;
	my $pass= 0;
	my $fail= 0;
	my $deleted = 0;
	my $inspect = 0;
	if ($nooutput{$exe}) {
		$total = 1;
		$pass = 1;
	} elsif (open (PRT, "report.log")) {
		while (<PRT>) {
			if (/^ *([0-9]+) *OF *([0-9]+) *TESTS WERE/) {
				$total += $2;
				$pass += $1;
			} elsif (/^ *([0-9NO]+) *TEST\(S\) ([A-Z]+)/) {
				my $num = $1 eq "NO" ? 0 : $1;
				if ($2 eq "FAILED") {
					$fail += $num;
				} elsif ($2 eq "DELETED") {
					$deleted += $num;
				} elsif ($2 eq "REQUIRE") {
					$inspect += $num;
				}
			} elsif (/^ *([0-9]+) *TESTS REQUIRE VISUAL INSPECTION/) {
				$total += $1;
				$inspect += $1;
			}
		}
	}
	printf LOG ("%5s %4s %4s %7s %7s %s\n",
		$total, $pass, $fail, $deleted, $inspect,
		$fail == 0 ? "OK" : "");
	$total_all += $total;
	$total_pass += $pass;
	$total_fail += $fail;
	$total_deleted += $deleted;
	$total_inspect += $inspect;
	$total_ok++ if $fail == 0;
	if ($exe eq "DB103M" && $db103m == 0) {
		$db103m = 1;
		$ENV{"COB_SET_DEBUG"} = "N";
		$num_progs++;
		print "Reexecution with runtime DEBUG off  ./DB103M\n";
		printf LOG "%-12s", $in;
		goto testrepeat;
	}
	rename ("report.log", "$exe.log");
	unlink "$exe.out" if (-s "$exe.out" == 0);
}

print LOG "--------    ----- ---- ---- ------- -------\n";
printf LOG ("Total       %5s %4s %4s %7s %7s\n\n",
	    $total_all, $total_pass, $total_fail, $total_deleted,
	    $total_inspect);

printf LOG ("Number of programs:    %2s\n", $num_progs);
printf LOG ("Successfully executed: %2s\n", $total_ok);
printf LOG ("Compile error:         %2s\n", $compile_error);
printf LOG ("Execute error:         %2s\n", $execute_error);
