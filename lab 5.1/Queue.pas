UNIT QUEUE;

INTERFACE
  TYPE
    DataType = INTEGER;

  FUNCTION Pop(): DataType;
  PROCEDURE Push(Elem: DataType; Priority: INTEGER);
  PROCEDURE ChangePriority(Elem: DataType; Priority: INTEGER);
  FUNCTION IsQueueEmpty(): BOOLEAN; 

IMPLEMENTATION
  TYPE
    NodeQ = ^Queue;
    Queue = RECORD
              Next: NodeQ;
              Data: DataType;
              Priority: INTEGER
            END;
  VAR
    Head: NodeQ;
    
  
  FUNCTION Pop(): DataType;
  VAR
    CopyQ: NodeQ;
    Elem: DataType;  
  BEGIN
    IF Head <> NIL
    THEN
      BEGIN
        CopyQ := Head;
        WRITELN('Priority: ', CopyQ^.Priority);
        Elem := Head^.Data;
        Head := Head^.Next;
        DISPOSE(CopyQ)
      END;
    Pop := Elem
  END;
  
  PROCEDURE Push(Elem: DataType; Priority: INTEGER);
  VAR
    CopyQ, AddQ: NodeQ;
  BEGIN
    CopyQ := Head;
    NEW(AddQ);
    AddQ^.Data := Elem;
    AddQ^.Priority := Priority;
    IF(Head <> NIL)
    THEN
      BEGIN
        WHILE((CopyQ^.Next <> NIL) AND (CopyQ^.Next^.Priority <= Priority))
        DO
          CopyQ := CopyQ^.Next;
            IF(CopyQ^.Priority > Priority)
            THEN
              BEGIN
                Head := AddQ;
                AddQ^.Next := CopyQ
              END
            ELSE
                BEGIN
                  IF(CopyQ^.Next <> NIL)
                  THEN
                    AddQ^.Next := CopyQ^.Next; 
                  CopyQ^.Next := AddQ
                END
        END
    ELSE
      Head := AddQ
  END;
  
  PROCEDURE ChangePriority(Elem: DataType; Priority: INTEGER);
  VAR
    CopyQ, OldQ: NodeQ;
    Flag: BOOLEAN;
  BEGIN
    Flag := FALSE;
    CopyQ := Head;
    OldQ := Head;
    WHILE((CopyQ <> NIL) AND (NOT Flag))
    DO
      BEGIN
        IF(CopyQ^.Data = Elem)
        THEN
          BEGIN
            WRITELN(1);
            IF(CopyQ^.Next <> NIL)
            THEN
              BEGIN
                IF(CopyQ = OldQ)
                THEN
                  Head := Head^.Next
                ELSE 
                  OldQ := CopyQ^.Next
              END;
            Push(Elem, Priority);
            DISPOSE(CopyQ);
            Flag := TRUE 
          END;
        OldQ := CopyQ;
        CopyQ := CopyQ^.Next
      END
  END;
  
  
  FUNCTION IsQueueEmpty(): BOOLEAN;
  BEGIN
    IsQueueEmpty := Head = NIL
  END;
  
BEGIN
  Head := NIL;
END.
