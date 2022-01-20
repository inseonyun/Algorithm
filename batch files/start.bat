@echo off
echo --------------------------------------------
echo 		Hello	
echo	1 : Create new Branch (name:batch)
echo	2 : Add, Commit, Push in origin
echo	3 : Pull upstream, Delete branch
echo --------------------------------------------

set newBranchName =
set /p newBranchName=Please Input new Branch Name : 

set batch_file_path="C:/Users/user/Desktop/batch files"
set git_file_path="D:/git_my_test/DingDong"
set git_address="https://github.com/inseonyun/DingDong"

:START
pushd %batch_file_path%

set input =
set /p input=Please Input 1 / 2 / 3 / q : 

if %input% == 1 (
	echo.
	echo wait . . . 
	echo.
	echo --------------------------------------------
	call "checkout.bat"
	echo.
	echo --------------------------------------------
) else if %input% == 2 (
	echo.
	echo wait . . . 
	echo.
	echo --------------------------------------------
	call "push.bat"
	echo.
	echo --------------------------------------------
) else if %input% == 3 (
	echo.
	echo wait . . . 
	echo.
	echo --------------------------------------------
	call "pull&delete.bat"
	echo. 
	echo --------------------------------------------
) else if /i %input% == q ( 
	exit
)
GOTO START
