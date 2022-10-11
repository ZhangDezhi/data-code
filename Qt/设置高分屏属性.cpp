#if (QT_VERSION > QT_VERSION_CHECK(5,6,0))
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif