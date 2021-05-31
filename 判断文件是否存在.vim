

:function! SomeCheck()
:   if filereadable("SpecificFile")
:       echo "SpecificFile exists"
:   endif
:endfunction



:if !empty(glob("path/to/file"))
:   echo "File exists."
:endif


if !empty(expand(glob("filename")))
    echo "File exists"
else
    echo "File does not exists"
endif



if filereadable('test.txt')    " 判断文件是否存在"
    echo 'file is exists'
endif


if filereadable(expand("$HOME/.vim/bundle/jedi-vim/Makefile"))    " 判断文件是否存在"
    echo 'jedi-vim is exists'
endif



:function! SomeCheck()
:   if findfile("SpecificFile",".") == "SpecificFile"
:       echo "SpecificFile exists"
:   endif
:endfunction



:function! SomeCheck()
:   if filereadable("SpecificFile")
:       echo "SpecificFile exists"
:   endif
:endfunction


