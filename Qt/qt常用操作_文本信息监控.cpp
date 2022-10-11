textChanged信号：每当文本改变时，就会发出这个信号。文本参数是新文本。

    与textEdited() 不同，当以编程方式更改文本时，例如，通过调用setText() 也会发出此信号。

    textEdited信号：每当文本被编辑时，就会发出这个信号。文本参数是新文本。

    与textChanged() 不同，当以编程方式更改文本时，例如，通过调用setText() 不会发出此信号。