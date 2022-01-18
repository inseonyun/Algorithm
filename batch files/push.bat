@echo off
pushd %git_file_path%
git add .
git commit -m "Added from batch file"
git push origin batch

start chrome.exe "https://github.com/inseonyun/DingDong"

echo Push Success