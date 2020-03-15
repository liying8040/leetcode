### 本地操作：

在本地创建文件夹，并在当前目录下添加希望上传的文件，例如，readme.md  
打开git bash，并进入当前文件夹目录（可利用`pwd`查看当前路径）    
`git init`							//将当前目录变成 git 可以管理的仓库  
`git add readme.md`		//将 readme.md 从工作区提交至暂存区  
`git commit -m "如何使用git"`	//从暂存区提交至本地master分支的仓库，并添加说明  
`git status`			//查看当前提交状态，检查是否有文件未提交  
`cat readme.md`	//查看 readme.md的内容  
`git reset --hard HEAD^`	//回退至上一版本（commit一次就产生一个版本）  
`git  log --pretty=oneline`	//查看之前版本号  
`git reflog XXX`		//回退至之前某一版本号  

### 推送至github：

//将本地仓库与某一repo关联  
`git remote add origin https://github.com/liying8040/cpp_git.git`  
//将本地仓库的master分支推送至元仓库，使用-u将本地master和远程master关联  
`git push -u origin master`  
//关联之后，以后每次都可以简化命令  
`git push origin master`  

### 从远程库克隆：

`git clone https://github.com/liying8040/cpp_git.git`  
