@echo off
REM Путь к тестируемой программе передаётся через 1-й агрумент командной строки
SET MyProgram="%~1"
REM Защита от запуска без агумнтов
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

REM тесты прошли успешно
echo All tests passed succesfuly
exit /B 0

REM Сюда будем попадать в случае ошибки
:err
echo Test failed
exit /B 1		