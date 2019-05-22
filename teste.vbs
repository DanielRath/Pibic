Set WshShell = WScript.CreateObject("WScript.Shell")
Comandline = "C:\Users\DanielRath\AppData\Roaming\Spotify\Spotify.exe"
WScript.sleep 500
CreateObject("WScript.Shell").Run("spotify:track:0Yb8wF1HLvel0RYqHHeAUi")
WScript.sleep 15000
WshShell.SendKeys "{ENTER}"
