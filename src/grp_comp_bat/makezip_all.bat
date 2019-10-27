REM for /d %f in (*) do call makezip.bat %f
FOR /F "delims=/" %%A IN ('DIR /AD /B')DO CALL makezip.bat "%%A"
PAUSE