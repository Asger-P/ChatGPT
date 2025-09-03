//---------------------------------------------------------------------------

#ifndef AjImageH
#define AjImageH
//---------------------------------------------------------------------------
struct AjBitmap
{
   int width  = 0;
   int height = 0;
   int stride = 0;            // bytes per row (always width * 4 here)
   std::vector<uint8_t> pixels; // RGBA, tightly packed (no row padding)

   bool empty() const
   {
      return pixels.empty() || width <= 0 || height <= 0;
   }

   uint8_t* scanline(int y)
   {
      return pixels.data() + y * stride;
   }

   const uint8_t* scanline(int y) const
   {
      return pixels.data() + y * stride;
   }
};
#endif
«