#
##
#

allmf:
	make clean
	make mftst1 mftst2 mftst3 mftst4 mfex01 mfex02 mfex03 mfex04 mfex05 mfex06 

alloc:
	make clean
	make octst1 octst2 octst3 octst4 ocex01 ocex02 ocex03 ocex04 ocex05 ocex06 

clean:
	rm -f rwtst1 rwtst2 rwtst3 rwtst4 *.c *.h
	rm -f rwex01 rwex02 rwex03 rwex04 rwex05 rwex06

clobber: clean
	rm -f REPORT1 REPORT2 REPORT3 REPORT4
	rm -f REPORT1mf REPORT2mf REPORT3mf REPORT4mf
	rm -f ex*reportmf.txt ex*report.txt

save:
	make clobber
	cd ..; rm -f cobreport.tar.Z cobreport.tar; tar cvzf cobreport.tar.Z cobreport

ctst1:
	make clean
	make -f cobtoc_makefile rwtst1

ctst2:
	make clean
	make -f cobtoc_makefile rwtst2

ctst3:
	make clean
	make -f cobtoc_makefile rwtst3

ctst4:
	make clean
	make -f cobtoc_makefile rwtst4

cex01:
	make clean
	make -f cobtoc_makefile rwex01

cex02:
	make clean
	make -f cobtoc_makefile rwex02

cex03:
	make clean
	make -f cobtoc_makefile rwex03

cex04:
	make clean
	make -f cobtoc_makefile rwex04

cex05:
	make clean
	make -f cobtoc_makefile rwex05

cex06:
	make clean
	make -f cobtoc_makefile rwex06

mftst1:
	make -f mf_makefile rwtst1
	export DD_STUDENT=./student.txt; export DD_REPORT1=./REPORT1mf; ./rwtst1

octst1:
	make -f cob_makefile rwtst1
	DD_STUDENT=./student.txt ./rwtst1

mftst2:
	make -f mf_makefile rwtst2
	export DD_CUSTORD=./custord.txt; export DD_REPORT2=./REPORT2mf; ./rwtst2

octst2:
	make -f cob_makefile rwtst2
	export DD_CUSTORD=./custord.txt; export DD_REPORT2=./REPORT2;  ./rwtst2

mftst3:
	make -f mf_makefile rwtst3
	export DD_STUDREC=./studrec.txt; export DD_REPORT3=./REPORT3mf;  ./rwtst3

octst3:
	make -f cob_makefile rwtst3
	DD_STUDREC=./studrec.txt ./rwtst3

mftst4:
	make -f mf_makefile rwtst4
	export DD_INVFILE=./invfile.txt; export DD_REPORT4=./REPORT4mf;  ./rwtst4

octst4:
	make -f cob_makefile rwtst4
	DD_INVFILE=./invfile.txt ./rwtst4

mfex01:
	make -f mf_makefile rwex01
	export DD_DATAIN=./ex01data.txt; export DD_SYSPRINT=./ex01reportmf.txt; ./rwex01

ocex01:
	make -f cob_makefile rwex01
	export DD_DATAIN=./ex01data.txt; export DD_SYSPRINT=./ex01report.txt; ./rwex01

mfex02:
	make -f mf_makefile rwex02
	export DD_DATAIN=./ex02data.txt; export DD_SYSPRINT=./ex02reportmf.txt; ./rwex02

ocex02:
	make -f cob_makefile rwex02
	export DD_DATAIN=./ex02data.txt; export DD_SYSPRINT=./ex02report.txt; ./rwex02

mfex03:
	make -f mf_makefile rwex03
	export DD_DATAIN=./ex03data.txt; export DD_SYSPRINT=./ex03reportmf.txt; ./rwex03

ocex03:
	make -f cob_makefile rwex03
	export DD_DATAIN=./ex03data.txt; export DD_SYSPRINT=./ex03report.txt; ./rwex03

mfex04:
	make -f mf_makefile rwex04
	export DD_DATAIN=./ex04data.txt; export DD_SYSPRINT=./ex04reportmf.txt; ./rwex04

ocex04:
	make -f cob_makefile rwex04
	export DD_DATAIN=./ex04data.txt; export DD_SYSPRINT=./ex04report.txt; ./rwex04

mfex05:
	make -f mf_makefile rwex05
	export DD_DATAIN=./ex05data.txt; export DD_SYSPRINT=./ex05reportmf.txt; ./rwex05

ocex05:
	make -f cob_makefile rwex05
	export DD_DATAIN=./ex05data.txt; export DD_SYSPRINT=./ex05report.txt; ./rwex05

mfex06:
	make -f mf_makefile rwex06
	export DD_DATAIN=./ex06data.txt; export DD_SYSPRINT=./ex06reportmf.txt; ./rwex06

ocex06:
	make -f cob_makefile rwex06
	export DD_DATAIN=./ex06data.txt; export DD_SYSPRINT=./ex06report.txt; ./rwex06

