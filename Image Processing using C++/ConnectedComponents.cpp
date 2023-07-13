void LabelImage(unsigned short width, unsigned short height, unsigned char* input, int* output);
unsigned short W = 640;
unsigned short H = 480;
Mat input (H, W, CV_8UC1);
Mat output(H, W, CV_32SC1, 0);
LabelImage(W, H, (unsigned char*)input.data, (int*)output.data);
void LabelImage(unsigned short width, unsigned short height, unsigned char* input, int* output)
{
  int labelNo = 0;
  int index   = -1;
  for (unsigned short y = 0; y < height; y++)
  {
    for (unsigned short x = 0; x < width; x++)
    {
      index++;
      if (input [index] == 0) continue;   
      if (output[index] != 0) continue;   
      labelNo++;
      LabelComponent(width, height, input, output, labelNo, x, y);
    }
  }
}
void LabelComponent(unsigned short width, unsigned short height, 
unsigned char* input, int* output, int labelNo, unsigned short x, unsigned short y)
{
  int index = x + width*y;
  if (input [index] == 0) return;
  if (output[index] != 0) return; 
  output[index] = labelNo;

  if (x > 0)        LabelComponent(width, height, input, output, labelNo, x-1, y); 
  if (x < width-1)  LabelComponent(width, height, input, output, labelNo, x+1, y); 
  if (y > 0)        LabelComponent(width, height, input, output, labelNo, x, y-1); 
  if (y < height-1) LabelComponent(width, height, input, output, labelNo, x, y+1);
}
#define CALL_LabelComponent(x,y,returnLabel) { STACK[SP] = x; 
STACK[SP+1] = y; STACK[SP+2] = returnLabel; SP += 3; goto START; }
#define RETURN { SP -= 3;                \
                 switch (STACK[SP+2])    \
                 {                       \
                 case 1 : goto RETURN1;  \
                 case 2 : goto RETURN2;  \
                 case 3 : goto RETURN3;  \
                 case 4 : goto RETURN4;  \
                 default: return;        \
                 }                       \
               }
#define X (STACK[SP-3])
#define Y (STACK[SP-2])

void LabelComponent(unsigned short* STACK, unsigned short width, unsigned short height, 
unsigned char* input, int* output, int labelNo, unsigned short x, unsigned short y)
{
  STACK[0] = x;
  STACK[1] = y;
  STACK[2] = 0; 
  int SP   = 3;
  int index;

START:

  index = X + width*Y;
  if (input [index] == 0) RETURN; 
  if (output[index] != 0) RETURN;  
  output[index] = labelNo;

  if (X > 0) CALL_LabelComponent(X-1, Y, 1);   /* left  pixel */
RETURN1:

  if (X < width-1) CALL_LabelComponent(X+1, Y, 2);   /* right pixel */
RETURN2:

  if (Y > 0) CALL_LabelComponent(X, Y-1, 3);   /* upper pixel */
RETURN3:

  if (Y < height-1) CALL_LabelComponent(X, Y+1, 4);   /* lower pixel */
RETURN4:

  RETURN;
}

void LabelImage(unsigned short width, unsigned short height, unsigned char* input, int* output)
{
  unsigned short* STACK = (unsigned short*) malloc(3*sizeof(unsigned short)*(width*height + 1));
  
  int labelNo = 0;
  int index   = -1;
  for (unsigned short y = 0; y < height; y++)
  {
    for (unsigned short x = 0; x < width; x++)
    {
      index++;
      if (input [index] == 0) continue; 
      if (output[index] != 0) continue; 
      labelNo++;
      LabelComponent(STACK, width, height, input, output, labelNo, x, y);
    }
  }

  free(STACK);
}
