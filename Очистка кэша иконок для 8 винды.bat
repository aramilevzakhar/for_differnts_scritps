rem отключаем вывод
@echo off

taskkill /F /IM explorer.exe rem убиваем процесс эксплорер
cd %userprofile%\AppData\Local rem переходим в директорию с файлом, который необходимо удалить
attrib -H IconCache.db rem вскрываем файл (он скрыт)
del IconCache.db rem удаляем его
cd %userprofile% rem переходим в директорию пользователя


start C:\Windows\explorer.exe