@echo off
REM ���� � ����������� ��������� ��������� ����� 1-� �������� ��������� ������
SET MyProgram="%~1"
REM ������ �� ������� ��� ��������
if MyProgram=="" (
	echo Please specify path to program 
	exit /B 1
)

REM Multiplication of the first matrix by the second
%MyProgram% "i1.txt" "i2.txt" > "output.txt" || goto err
fc "output.txt" "i1xi2-out.txt" || goto err
echo Test 1 passed

REM Multiplication of the first matrix by the third (float)
%MyProgram% "i1.txt" "i3.txt" > "output.txt" || goto err
fc "output.txt" "i1xi3-out.txt" || goto err
echo Test 2 passed

REM String instead of number
%MyProgram% "i1.txt" "StringInsteadOfNumber.txt" > "output.txt" && goto err
echo Test 3 passed

REM Not enough numbers
%MyProgram% "i1.txt" "NotEnoughNumbers.txt" > "output.txt" && goto err
echo Test 4 passed

REM Copy missing file should fail
%MyProgram% missingfile.txt missingfile.txt > output.txt && goto err
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