@echo off
pushd %git_file_path%

set /p message=Commit Message Input : 

git add .
git commit -m "%message%"
git push origin %newBranchName%

start chrome.exe %git_address%

echo Push Success