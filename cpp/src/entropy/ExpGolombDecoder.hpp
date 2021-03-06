/*
Copyright 2011-2017 Frederic Langlet
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
you may obtain a copy of the License at

                http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef _ExpGolombDecoder_
#define _ExpGolombDecoder_

#include "../EntropyDecoder.hpp"

namespace kanzi 
{

   class ExpGolombDecoder : public EntropyDecoder 
   {
   private:
       InputBitStream& _bitstream;
       bool _signed;

       void flush();

   public:
       ExpGolombDecoder(InputBitStream& bitstream, bool sign=true);

       ~ExpGolombDecoder() { dispose(); }

       int decode(byte arr[], uint blkptr, uint len);

       InputBitStream& getBitStream() const { return _bitstream; };

       byte decodeByte();

       void dispose() {}

       bool isSigned() const { return _signed; }
   };

}
#endif
