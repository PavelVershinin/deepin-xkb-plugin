# deepin-xkb-plugin
Добавляем иконку с отображением текущей раскладки в трей Deepin

Собранную программу кидаем в /usr/bin
Создаём файл ~/.config/autostart/deepin-xkb-plugin.desktop со следующим содержимым:

#!/usr/bin/env xdg-open

[Desktop Entry]
Version=1.0
Name=deepin-xkb-plugin
Comment=Индикатор раскладки клавиатуры
Exec=/usr/bin/deepin-xkb-plugin
Terminal=false
X-MultipleArgs=false
Type=Application
Icon=
Categories=Network;
StartupNotify=true
X-Deepin-CreatedBy=com.deepin.SessionManager
X-Deepin-AppID=deepin-xkb-plugin
Hidden=false


Перезагружаем комп и наслаждаемся)))


![Иллюстрация к проекту](https://github.com/PavelVershinin/deepin-xkb-plugin/blob/master/screenshot.png)
