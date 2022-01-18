@echo off
pushd %git_file_path%
git checkout master
git pull upstream master
git branch -D batch
git push origin :batch
git push

echo Pull And Delete Branch 