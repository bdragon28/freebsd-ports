--- gcc/config/powerpcspe/freebsd.h.orig	2019-02-21 22:13:21.879120000 -0600
+++ gcc/config/powerpcspe/freebsd.h	2019-02-21 22:14:32.420389000 -0600
@@ -43,6 +43,15 @@
 #undef  LINK_SHLIB_SPEC
 #define LINK_SHLIB_SPEC "%{shared:-shared} %{!shared: %{static:-static}}"
 
+/* Force 32 bit assembly. XXX: review the rest of this def, it's from sysv4.h */
+#undef  ASM_SPEC
+#define ASM_SPEC "-a32 %(asm_cpu) \
+%{,assembler|,assembler-with-cpp: %{mregnames} %{mno-regnames}} \
+%{mrelocatable} %{mrelocatable-lib} %{" FPIE_OR_FPIC_SPEC ":-K PIC} \
+%{memb|msdata=eabi: -memb}" \
+ENDIAN_SELECT(" -mbig", " -mlittle", DEFAULT_ASM_ENDIAN)
+
+
 
 /************************[  Target stuff  ]***********************************/
 
