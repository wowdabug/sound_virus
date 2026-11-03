$CONSOLE = $false

$flags = if ($CONSOLE) {""} else {"-mwindows"}

Write-Output "Compiling... (debug)"
gcc -o debug main.c miniaudio.c -std=c23 -O0 -Wall -Wextra -Werror -Wpedantic $flags

if ($LASTEXITCODE -eq 0) {
	Write-Output "Running..."
	./debug.exe
}
