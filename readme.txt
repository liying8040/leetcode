在本地创建文件夹，并在当前目录下添加希望上传的文件，例如，a.cpp
打开git bash，并进入当前文件夹目录（可利用pwd查看当前路径）
git init             //将当前目录变成 git 可以管理的仓库
git add a.cpp  //将 a.cpp 提交至暂存区
git commit -m "提交a.cpp"   //将 a.cpp 提交至默认master分支的仓库，并添加说明文字
git status        //查看当前提交状态，检查是否有文件未提交
cat a.cpp         //查看 a.cpp 的内容
git  

