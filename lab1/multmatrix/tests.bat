@echo off
REM Путь к тестируемой программе передаётся через 1-й агрумент командной строки
SET MyProgram="%~1"
REM Защита от запуска без агумнтов
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

REM тесты прошли успешно
echo All tests passed succesfuly
exit /B 0

REM Сюда будем попадать в случае ошибки
:err
echo Test failed
exit /B 1		