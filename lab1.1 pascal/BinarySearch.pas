PROGRAM BinarySearch(INPUT, OUTPUT);

CONST
  MaxArraySize = 32767;

TYPE 
  NumArray = ARRAY[0..MaxArraySize] OF INTEGER;
VAR
  NumsArray: NumArray;
  NumNow, ArraySize, Number: INTEGER;
  InputFile, OutputFile: TEXT;


FUNCTION GetMiddle(StartNum, EndNum: INTEGER): INTEGER;
BEGIN
  GetMiddle := TRUNC((StartNum + EndNum) / 2)
END;


PROCEDURE BinarySearch(VAR Nums: NumArray; Size, Number: INTEGER);
VAR
  PositionNow, OldPosition: INTEGER;
  Found: BOOLEAN;
BEGIN
  OldPosition := 0;
  Found := FALSE;
  PositionNow := GetMiddle(0, Size);
  WHILE (NOT Found)
  DO
    BEGIN
      IF(Nums[PositionNow] = Number)
      THEN
        BEGIN
          Found := TRUE;
          WRITELN(PositionNow)
        END
      ELSE
        IF((PositionNow = Size) OR (PositionNow = 0) OR (PositionNow = OldPosition))
        THEN
          BEGIN
            Found := TRUE;
            WRITELN('-1')
          END;      
      IF(Nums[PositionNow] > Number)
      THEN
        PositionNow := GetMiddle(OldPosition, PositionNow)
      ELSE
        BEGIN
          OldPosition := PositionNow;
          PositionNow := GetMiddle(PositionNow, Size)
        END
    END
END;


BEGIN
  ASSIGN(InputFile, 'Inp.txt');
  ASSIGN(OutputFile, 'Out.txt');
  RESET(InputFile);
  NumNow := 0;
  ArraySize := 0;
  WHILE(NOT EOLN(InputFile))
  DO
    BEGIN
      READ(InputFile, NumNow);
      NumsArray[ArraySize] := NumNow;
      ArraySize := ArraySize + 1  
    END;
  
  WRITE('¬ведите число: ');
  READ(INPUT, Number);
  BinarySearch(NumsArray, ArraySize, Number);
END.
