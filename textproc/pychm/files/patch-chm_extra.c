--- chm/extra.c.orig	2015-07-05 03:15:19 UTC
+++ chm/extra.c
@@ -70,13 +70,13 @@
 
 #define FREE(x) free (x); x = NULL
 
-inline uint16_t 
+uint16_t 
 get_uint16 (uint8_t* b) {
   return b[0] |
     b[1]<<8;
 }
 
-inline uint32_t 
+uint32_t 
 get_uint32 (uint8_t* b) {
   return b[0] |
     b[1]<<8   |
@@ -84,7 +84,7 @@ get_uint32 (uint8_t* b) {
     b[3]<<24;
 }
 
-inline uint64_t 
+uint64_t 
 get_uint64 (uint8_t* b) {
   return b[0]           |
     b[1]<<8             |
@@ -117,7 +117,7 @@ be_encint (unsigned char *buffer, size_t
   Finds the first unset bit in memory. Returns the number of set bits found.
   Returns -1 if the buffer runs out before we find an unset bit.
 */
-inline int
+int
 ffus (unsigned char* byte, int* bit, size_t *length) {
   int bits = 0;
   *length = 0;
@@ -144,7 +144,7 @@ ffus (unsigned char* byte, int* bit, siz
 }
 
 
-inline uint64_t
+uint64_t
 sr_int(unsigned char* byte, int* bit,
        unsigned char s, unsigned char r, size_t *length)
 {
@@ -221,7 +221,7 @@ sr_int(unsigned char* byte, int* bit,
 }
 
             
-inline uint32_t
+uint32_t
 get_leaf_node_offset(struct chmFile *chmfile,
                      const char *text,
                      uint32_t initial_offset,
@@ -294,7 +294,7 @@ get_leaf_node_offset(struct chmFile *chm
   return initial_offset;
 }
 
-inline int 
+int 
 pychm_process_wlc (struct chmFile *chmfile,
                    uint64_t wlc_count, uint64_t wlc_size,
                    uint32_t wlc_offset, unsigned char ds,
