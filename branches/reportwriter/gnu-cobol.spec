# RPM spec file for gnu-cobol
# Adjust/activate "Packager" tag as necessary

Name:		gnu-cobol
Version:	2.1
Release:	1%{?dist}
Summary:	GNU Cobol - COBOL compiler

# Packager:	Whoever

Group:		Development/Languages/Other
License:	GPL/LGPL

URL:		http://www.gnu.org/software/gnucobol
# Source:	http://downloads.sourceforge.net/%{name}/%{name}-%{version}.tar.gz
Source:		http://www.sim-basis.de/%{name}-%{version}.tar.gz

BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires:	gcc
BuildRequires:	glibc-devel
BuildRequires:	glibc
BuildRequires:  gmp-devel >= 4.1.4
BuildRequires:	gmp >= 4.1.4
BuildRequires:	db-devel >= 4.1.24
BuildRequires:	db >= 4.1.24
BuildRequires:	ncurses-devel >= 5.4
BuildRequires:	ncurses >= 5.4

Requires:       gcc
Requires:	glibc
Requires:	glibc-devel
Requires:       gmp >= 4.1.4
Requires:       gmp-devel >= 4.1.4
Requires:       db >= 4.1.24
Requires:       ncurses >= 5.4

Requires(post): /sbin/install-info

%description
GNU Cobol is an open-source COBOL compiler, which translates COBOL
programs to C code and compiles it using GCC.

%prep
%setup -q -n %{name}-%{version}

%build
%configure --disable-rpath
make

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT
rm -rf $RPM_BUILD_ROOT/%{_infodir}/dir

%find_lang %{name}

%check
make check

%files -f %{name}.lang
%defattr (-,root,root,-)
%doc AUTHORS COPYING COPYING.LESSER COPYING.DOC ChangeLog
%doc NEWS README THANKS
%{_bindir}/cobc
%{_bindir}/cobcrun
%{_bindir}/cob-config
%{_includedir}/*
%{_datadir}/gnu-cobol
%{_infodir}/gnu-cobol.info*
%{_libdir}/libcob.so*
%{_libdir}/libcob.a
%{_libdir}/libcob.la

%clean
rm -rf $RPM_BUILD_ROOT
rm -rf $RPM_BUILD_DIR/%{name}-%{version}

%post 
/sbin/install-info %{_infodir}/gnu-cobol.info %{_infodir}/dir 2>/dev/null || :
/sbin/ldconfig

%postun 
if [ $1 = 0 ]; then
  /sbin/install-info --delete %{_infodir}/gnu-cobol.info %{_infodir}/dir 2>/dev/null || :
fi
/sbin/ldconfig

%changelog
