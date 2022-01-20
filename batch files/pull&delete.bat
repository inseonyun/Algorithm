@echo off
pushd %git_file_path%
git checkout master
git pull upstream master
git branch -D %newBranchName%
git push origin :%newBranchName%
git push

echo Pull And Delete "%newBranchName%"