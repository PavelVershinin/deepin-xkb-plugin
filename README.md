# deepin-xkb-plugin
Добавляем иконку с отображением текущей раскладки в трей Deepin

Собранную программу кидаем в /usr/bin
Создаём файл ~/.config/autostart/deepin-xkb-plugin.desktop со следующим содержимым:

#!/usr/bin/env xdg-open

[Desktop Entry]
Name=deepin-xkb-plugin
Comment=Индикатор раскладки клавиатуры
Exec=/usr/bin/deepin-xkb-plugin
Terminal=false 
X-MultipleArgs=false 
Type=Application 

Перезагружаем комп и наслаждаемся)))


![Иллюстрация к проекту](https://github.com/PavelVershinin/deepin-xkb-plugin/blob/master/screenshot.png)
