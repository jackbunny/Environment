if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <silent> <S-Tab> =BackwardsSnippet()
snoremap <silent> 	 i<Right>=TriggerSnippet()
snoremap  b<BS>
snoremap % b<BS>%
snoremap ' b<BS>'
snoremap U b<BS>U
snoremap \ b<BS>\
snoremap ^ b<BS>^
snoremap ` b<BS>`
nmap gx <Plug>NetrwBrowseX
snoremap <Left> bi
snoremap <Right> a
snoremap <BS> b<BS>
snoremap <silent> <S-Tab> i<Right>=BackwardsSnippet()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
nmap <silent> <F12> <Plug>ToggleProject
map <C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .
noremap <silent> <F8> :NERDTreeToggle
noremap <silent> <F9> :TagbarToggle  
inoremap <silent> 	 =TriggerSnippet()
inoremap <silent> 	 =ShowAvailableSnips()
inoremap <expr>  omni#cpp#maycomplete#Complete()
inoremap <expr> . omni#cpp#maycomplete#Dot()
inoremap <expr> : omni#cpp#maycomplete#Scope()
inoremap <expr> > omni#cpp#maycomplete#Arrow()
cnoreabbr Tree NERDTree
let &cpo=s:cpo_save
unlet s:cpo_save
set background=dark
set backspace=indent,eol,start
set cindent
set completeopt=menu,menuone
set expandtab
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set omnifunc=omni#cpp#complete#Main
set printoptions=paper:letter
set ruler
set runtimepath=~/.vim,~/.vim/bundle/NERDTree,~/.vim/bundle/indexer,~/.vim/bundle/omnicomplete,~/.vim/bundle/project,~/.vim/bundle/snipmate,~/.vim/bundle/tagbar,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/bundle/omnicomplete/after,~/.vim/bundle/snipmate/after,~/.vim/after
set shiftwidth=3
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tags=./tags,./TAGS,tags,TAGS,~/.vim/tags/cpp,~/.vim/tags/gl
set window=44
" vim: set ft=vim :
