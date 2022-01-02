echo WScript.sleep 500>sss.vbs

start ATdbServer.bat
sss.vbs
start ATGateServer.bat
sss.vbs
start ATLoginServer.bat