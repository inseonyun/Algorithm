@echo off
pushd %git_file_path%
git pull
git checkout -b batch

echo Create New Branch