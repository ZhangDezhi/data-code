//qcolor -> qstring
QString ColorHelper::makeColorString(const QColor &color, const QString type)
{
    if(type == "RGBA") {
        return QString("rgba(%1, %2, %3, %4)")
                .arg(color.red())
                .arg(color.green())
                .arg(color.blue())
                .arg(color.alpha());
    }
    if(type == "RGB") {
        return QString("rgba(%1, %2, %3)")
                .arg(color.red())
                .arg(color.green())
                .arg(color.blue());
    }
    if(type == "HEX") {
        return QString().sprintf("#%1%02X%02X%02X",
                                 color.red(),
                                 color.green(),
                                 color.blue()).arg(color.alpha() != 255 ? QString().sprintf("%02X", color.alpha()) : QString());
    }
 
    return color.name();
}
 