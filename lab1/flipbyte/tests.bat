@echo off
REM ���� � ����������� ��������� ��������� ����� 1-� �������� ��������� ������
SET MyProgram="%~1"
REM ������ �� ������� ��� ��������
if MyProgram=="" (
	echo Please specify path to program 
	exit /B 1
)

REM Enter 6
%MyProgram% 6 > output.txt || goto err
fc "output.txt" "96.txt" || goto err
echo Test 1 passed

REM Enter 255
%MyProgram% 255 > output.txt || goto err
fc  "output.txt" "255.txt" || goto err
echo Test 2 passed

REM Enter 0
%MyProgram% 0 > output.txt || goto err
fc  "output.txt" "0.txt" || goto err
echo Test 3 passed

REM Enter 264
%MyProgram% 264 > output.txt && goto err
echo Test 4 passed

REM Do not enter a number
%MyProgram% > output.txt && goto err
echo Test 4 passed

REM Enter a string instead of a number
%MyProgram% "string" > output.txt  && goto err
echo Test 5 passed

REM ����� ������ �������
echo All tests passed succesfuly
exit /B 0

REM ���� ����� �������� � ������ ������
:err
echo Test failed
exit /B 1		