@echo off
pushd %git_file_path%

git pull
git checkout -b %newBranchName%

echo Create New Branch : "%newBranchName%"