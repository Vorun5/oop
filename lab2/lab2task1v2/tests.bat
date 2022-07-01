@echo off
REM ���� � ����������� ��������� ��������� ����� 1-� �������� ��������� ������
SET MyProgram="%~1"
REM ������ �� ������� ��� ��������
if MyProgram=="" (
	echo Please specify path to program 
	exit /B 1
)

REM Enter not a numbers
%MyProgram% < "no numbers.txt" > output.txt || goto err
fc "output.txt" "no numbers-out.txt" || goto err
echo Test 1 passed

REM Minimum element 1
%MyProgram% < i1.txt > output.txt || goto err
fc  "output.txt" "i1-out.txt" || goto err
echo Test 2 passed

REM Test 3
 %MyProgram% < i2.txt > output.txt || goto err
fc  "output.txt" "i2-out.txt" || goto err
echo Test 3 passed

REM Test 4
 %MyProgram% < i3.txt > output.txt || goto err
fc  "output.txt" "i3-out.txt" || goto err
echo Test 4 passed

REM Minimum element 0
%MyProgram% < i4.txt > output.txt || goto err
fc  "output.txt" "i4-out.txt" || goto err
echo Test 5 passed

REM ����� ������ �������
echo All tests passed succesfuly
exit /B 0

REM ���� ����� �������� � ������ ������
:err
echo Test failed
exit /B 1		