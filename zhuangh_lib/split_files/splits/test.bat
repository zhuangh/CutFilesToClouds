rem
rem MS-DOS test script for splits
rem
copy /b splits.exe+splits.c+splits.exe+splits.c+splits.exe+splits.exe test.bak
copy /b test.bak+test.bak+test.bak+test.bak test1.bak
copy /b test1.bak+test1.bak+test1.bak+test1.bak+test1.bak test
del test1.bak
splits test
copy /b test.0* test1.bak
echo N | comp test1.bak test
del test.0*
del test1.bak
del test
type splits.c | splits - 1
copy /b StdIn.0* test.bak
echo N | comp test.bak splits.c
del StdIn.0*
del test.bak
