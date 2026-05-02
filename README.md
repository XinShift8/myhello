# 我的 Linux / PA0 环境配置记录

## 1. VMware 与 Ubuntu 环境

主机 虚拟机 系统：

```text
Windows VMware VMware
```

## 2. VMware 代理

走 Windows 主机上的 Clash Verge 代理端口 https://zhuanlan.zhihu.com/p/2008250803064939901

通过 `ipconfig` 查看 VMnet8 地址，例如：

```text
VMnet8: 192.168.xxx.yyy
```

在 Clash Verge 中需要开启：

```text
允许局域网连接 / Allow LAN
```

并记住代理端口，例如：

```text
7890
```

## 3. 共享剪贴板

安装 VMware Tools：

```bash
sudo apt update #必要时， --fix-missing
sudo apt install open-vm-tools open-vm-tools-desktop -y
sudo reboot
```

检查版本和服务：

```bash
vmware-toolbox-cmd -v
systemctl status vmtoolsd
```

在 VMware 设置中确认：

```text
虚拟机设置 -> 选项 -> 客户机隔离
启用拖放
启用复制和粘贴
```

终端里的复制粘贴快捷键多按个shift：

## 4. 必会：

包括但不限于 `Makefile gdb tmux`：

## 5. Git

### 配置 SSH key：

```bash
~/.ssh/id_ed25519
~/.ssh/id_ed25519.pub
```

如果 22 端口被重置，例如：

```text
Connection reset by ... port 22
```

可以让 GitHub SSH 走 443 端口。

编辑：

```bash
vim ~/.ssh/config
```

写入：

```sshconfig
Host github.com
    Hostname ssh.github.com
    Port 443
    User git
```

设置权限：

```bash
chmod 600 ~/.ssh/config
```

再测试：

```bash
ssh -T git@github.com
```

### 基操：

GitHub 给了我 noreply 邮箱，避免真实邮箱暴露在公开 commit 记录里。

常用

```bash
init status diff add commit log 
```

### gitignore

编译产物不应该提交到 GitHub。

示例 `.gitignore`：

```gitignore
hello
*.o
```

检查 Git 实际追踪的文件：

```bash
git ls-files
```

13. 推送到 GitHub

本地已有仓库和 commit 后，需要在 GitHub 网页新建一个空仓库。

仓库名示例：

```text
myhello
```

创建时不要勾选：

```text
Add a README file
Add .gitignore
Choose a license
```

因为本地已经有文件和 commit。

添加远程仓库：

```bash
git remote add origin git@github.com:XinShift8/myhello.git
```

检查：

```bash
git remote -v
```

推送本地 master 分支：

```bash
git push -u origin master
```

成功信息类似：

```text
[new branch]      master -> master
Branch 'master' set up to track remote branch 'master' from 'origin'.
```

以后同一个分支再次推送，只需要：

```bash
git push
```

---

### 日常流程

日常工作流程：

```bash
vim hello.c
make
./hello
git status
git diff
git add hello.c
git commit -m "Update hello output"
git push
```

如果使用 VS Code Remote-SSH，则：

```text
VS Code 里编辑并保存
回到 Ubuntu 终端执行 make / gdb / git
```

---

## 6. VSCode SSH

目标：

```text
Windows 上装 VS Code
Ubuntu 虚拟机里不装 VS Code
VS Code 通过 SSH 连接 Ubuntu，直接编辑 Ubuntu 里的文件
```

Ubuntu 侧安装 SSH server：

```bash
sudo apt update
sudo apt install openssh-server -y
sudo systemctl enable --now ssh
systemctl status ssh # 检查服务
hostname -I #查ip
```

Windows PowerShell 测试连接：

```powershell
ssh usrname@Ubuntu_IP
```

VS Code 操作：

```text
安装 Remote - SSH 插件
点击左下角 >< 图标
选择 Connect to Host...
Add New SSH Host...
输入 ssh usrname@Ubuntu_IP
选择 Linux
输入 Ubuntu 密码
Open Folder
```