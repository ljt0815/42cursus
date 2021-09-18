rm -rf ~/.vimrc
touch ~/.vimrc
echo "if has(\"syntax\")" >> ~/.vimrc
echo "	syntax on" >> ~/.vimrc
echo "endif" >> ~/.vimrc
echo "set hlsearch" >> ~/.vimrc
echo "set nu" >> ~/.vimrc
echo "set autoindent" >> ~/.vimrc
echo "set smartindent" >> ~/.vimrc
echo "set cindent" >> ~/.vimrc
echo "set showmatch" >> ~/.vimrc
echo "let @t = \":Stdheader\\<CR>\"" >> ~/.vimrc
export MAIL="jitlee@student.42seoul.kr"
#mkdir -p ~/.vim/plugin
#cp stdheader.vim ~/.vim/plugin/
#if [ ! -z "$USER" ]
#then
#    USER=`/usr/bin/whoami`
#    export USER
#fi
#
#if [ ! -z "$GROUP" ]
#then
#    GROUP=`/usr/bin/id -gn $user`
#    export GROUP
#fi
alias cc="gcc -Werror -Wall -Wextra"
rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update
brew install readline
