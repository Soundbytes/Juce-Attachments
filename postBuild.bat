rem
rem POST BUILD EVENT
rem usage: call "$(ProjectDir)..\..\..\postBuild.bat" "$(TargetExt)" $(Platform) $(TargetPath) $(ProjectDir)
rem

if %1 == ".dll" (
rem move $(TargetPath) $(ProjectDir)..\..\..\..\..\Vst2\$(Platform)\
	move %3 %4..\..\..\..\..\Vst2\%2\	
) else (
	Echo "hier mach ich mal nix!"
)