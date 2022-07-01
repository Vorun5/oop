@echo off
REM ���� � ����������� ��������� ��������� ����� 1-� �������� ��������� ������
SET MyProgram="%~1"
REM ������ �� ������� ��� ��������
if MyProgram=="" (
	echo Please specify path to program 
	exit /B 1
)

REM Copy empty file
%MyProgram% "empty.txt" "some text" > output.txt || goto err
fc "output.txt" "emptyOutput.txt" || goto err
echo Test 1 passed

REM Copy no empty file
%MyProgram% "cat.txt" "cat" > output.txt || goto err
fc  "output.txt" "catOutput.txt" || goto err
echo Test 2 passed

REM Copy missing file should fail
%MyProgram% missingfile.txt "some text" > output.txt && goto err
echo Test 3 passed

REM If the search text is empty
%MyProgram% "cat.txt" "" > output.txt && goto err
echo Test 4 passed

REM If text to search is not specified, program must fail
%MyProgram% "missingfile.txt" > output.txt && goto err
echo Test 5 passed

REM If input file is are not specified, program must fail
%MyProgram% > output.txt  && goto err
echo Test 6 passed

REM ����� ������ �������
echo All tests passed succesfuly
exit /B 0

REM ���� ����� �������� � ������ ������
:err
echo Test failed
exit /B 1		