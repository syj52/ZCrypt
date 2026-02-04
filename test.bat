@echo off
:: test.bat
:: Zcrypt 测试脚本


:: 切换代码页
chcp 65001 > nul

echo.
echo 正在启动测试
echo 输入文件: test_data.txt
echo 输出文件: res.txt
echo ----------------------------


:: 定义路径
set EXE_PATH=.\build\src\Debug\Zcrypt.exe
set INPUT_FILE=.\test_data.txt
set OUTPUT_FILE=.\res.txt


:: 检查文件
if not exist "%EXE_PATH%" (
    echo 错误：未找到可执行文件 %EXE_PATH%
    echo 请先编译项目。
    pause
    exit /b 1
)


if not exist "%INPUT_FILE%" (
    echo 错误：未找到测试输入文件 %INPUT_FILE%
    pause
    exit /b 1
)

:: 运行程序
"%EXE_PATH%" -c null -e null -f "%INPUT_FILE%" -o "%OUTPUT_FILE%"

:: 检查结果
if %errorlevel% neq 0 (
    echo.
    echo 程序运行失败，错误代码: %errorlevel%
) else (
    echo.
    echo 测试执行成功！
)

echo ----------------------------------------
echo 测试完成。
pause > nul