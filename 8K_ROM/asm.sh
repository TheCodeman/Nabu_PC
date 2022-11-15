z80asm --list=nabupc-8k.lst  NabuPC-8K.z80  -o nabu-8k.bin
truncate -s 8192 nabu-8k.bin
./check
md5sum nabu-8k.bin
md5sum NabuPC-2764.bin
