$CONSOLE = $false

$flags = if ($CONSOLE) {""} else {"-mwindows"}

Write-Output "Compiling... (release)"
gcc -o release main.c miniaudio.c -std=c23 -O2 -Wall -Wextra -Werror -Wpedantic $flags

if ($LASTEXITCODE -eq 0) {
	Write-Output "Running..."
	./release.exe
}
