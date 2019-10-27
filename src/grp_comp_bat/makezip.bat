@echo on
set dir=%1
cd "%dir%"
echo %dir:~1,-1%
C:\Soft\Archive-Soft\7-Zip\7za.exe a "..\%dir:~1,-1%.zip" -ir!.\*.jpg -ir!.\*.png -ir!.\*.gif -ir!.\*.jpeg
cd ..
