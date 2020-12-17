ui->textBrowser->insertPlainText() ，插入文本可是在输出的内容的时候输出的位置不确定有时按顺序依次向下输出，有时在中间输出！

textBrowser->textCursor().insertText();// 插入文本到光标位置
textBrowser->moveCursor(QTextCursor::End);//