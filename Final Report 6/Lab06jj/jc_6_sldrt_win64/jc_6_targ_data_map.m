  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (jc_6_P)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% jc_6_P.AnalogOutput_FinalValue
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jc_6_P.AnalogOutput_InitialValue
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% jc_6_P.EncoderInput_InputFilter
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% jc_6_P.EncoderInput1_InputFilter
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% jc_6_P.EncoderInput_MaxMissedTicks
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% jc_6_P.EncoderInput1_MaxMissedTicks
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% jc_6_P.AnalogOutput_MaxMissedTicks
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% jc_6_P.EncoderInput_YieldWhenWaiting
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% jc_6_P.EncoderInput1_YieldWhenWaiting
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% jc_6_P.AnalogOutput_YieldWhenWaiting
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% jc_6_P.fast1_x0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% jc_6_P.fast2_x0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% jc_6_P.slow1_x0
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% jc_6_P.slow2_x0
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% jc_6_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jc_6_P.EncoderInput1_Channels
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% jc_6_P.AnalogOutput_Channels
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% jc_6_P.AnalogOutput_RangeMode
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
	  ;% jc_6_P.AnalogOutput_VoltRange
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% jc_6_P.TransferFcn_A
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jc_6_P.TransferFcn_C
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 2;
	
	  ;% jc_6_P.Gain_Gain
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 4;
	
	  ;% jc_6_P.safety_Gain
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 5;
	
	  ;% jc_6_P.Constant1_Value
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 6;
	
	  ;% jc_6_P.Gain3_Gain
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 7;
	
	  ;% jc_6_P.Saturation_UpperSat
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 8;
	
	  ;% jc_6_P.Saturation_LowerSat
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 9;
	
	  ;% jc_6_P.Gain2_Gain
	  section.data(9).logicalSrcIdx = 27;
	  section.data(9).dtTransOffset = 10;
	
	  ;% jc_6_P.Gain1_Gain
	  section.data(10).logicalSrcIdx = 28;
	  section.data(10).dtTransOffset = 11;
	
	  ;% jc_6_P.Constant_Value
	  section.data(11).logicalSrcIdx = 29;
	  section.data(11).dtTransOffset = 12;
	
	  ;% jc_6_P.Admatrix_Gain
	  section.data(12).logicalSrcIdx = 30;
	  section.data(12).dtTransOffset = 13;
	
	  ;% jc_6_P.Bdmatrix_Gain
	  section.data(13).logicalSrcIdx = 31;
	  section.data(13).dtTransOffset = 29;
	
	  ;% jc_6_P.Cdmatrix_Gain
	  section.data(14).logicalSrcIdx = 32;
	  section.data(14).dtTransOffset = 33;
	
	  ;% jc_6_P.Ddmatrix_Gain
	  section.data(15).logicalSrcIdx = 33;
	  section.data(15).dtTransOffset = 37;
	
	  ;% jc_6_P.Ldmatrix_Gain
	  section.data(16).logicalSrcIdx = 34;
	  section.data(16).dtTransOffset = 38;
	
	  ;% jc_6_P.Admatrix_Gain_i
	  section.data(17).logicalSrcIdx = 35;
	  section.data(17).dtTransOffset = 42;
	
	  ;% jc_6_P.Bdmatrix_Gain_e
	  section.data(18).logicalSrcIdx = 36;
	  section.data(18).dtTransOffset = 58;
	
	  ;% jc_6_P.Cdmatrix_Gain_e
	  section.data(19).logicalSrcIdx = 37;
	  section.data(19).dtTransOffset = 62;
	
	  ;% jc_6_P.Ddmatrix_Gain_m
	  section.data(20).logicalSrcIdx = 38;
	  section.data(20).dtTransOffset = 70;
	
	  ;% jc_6_P.Ldmatrix_Gain_b
	  section.data(21).logicalSrcIdx = 39;
	  section.data(21).dtTransOffset = 72;
	
	  ;% jc_6_P.Admatrix_Gain_b
	  section.data(22).logicalSrcIdx = 40;
	  section.data(22).dtTransOffset = 80;
	
	  ;% jc_6_P.Bdmatrix_Gain_e0
	  section.data(23).logicalSrcIdx = 41;
	  section.data(23).dtTransOffset = 96;
	
	  ;% jc_6_P.Cdmatrix_Gain_er
	  section.data(24).logicalSrcIdx = 42;
	  section.data(24).dtTransOffset = 100;
	
	  ;% jc_6_P.Ddmatrix_Gain_c
	  section.data(25).logicalSrcIdx = 43;
	  section.data(25).dtTransOffset = 104;
	
	  ;% jc_6_P.Ldmatrix_Gain_n
	  section.data(26).logicalSrcIdx = 44;
	  section.data(26).dtTransOffset = 105;
	
	  ;% jc_6_P.Admatrix_Gain_c
	  section.data(27).logicalSrcIdx = 45;
	  section.data(27).dtTransOffset = 109;
	
	  ;% jc_6_P.Bdmatrix_Gain_d
	  section.data(28).logicalSrcIdx = 46;
	  section.data(28).dtTransOffset = 125;
	
	  ;% jc_6_P.Cdmatrix_Gain_h
	  section.data(29).logicalSrcIdx = 47;
	  section.data(29).dtTransOffset = 129;
	
	  ;% jc_6_P.Ddmatrix_Gain_a
	  section.data(30).logicalSrcIdx = 48;
	  section.data(30).dtTransOffset = 137;
	
	  ;% jc_6_P.Ldmatrix_Gain_h
	  section.data(31).logicalSrcIdx = 49;
	  section.data(31).dtTransOffset = 139;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (jc_6_B)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% jc_6_B.TransferFcn
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jc_6_B.Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% jc_6_B.DataTypeConversion
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% jc_6_B.Gain3
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% jc_6_B.Gain2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% jc_6_B.Gain1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% jc_6_B.UnitDelay
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% jc_6_B.UnitDelay_o
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% jc_6_B.Constant
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% jc_6_B.UnitDelay_l
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
	  ;% jc_6_B.UnitDelay_c
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 19;
	
	  ;% jc_6_B.Sum3
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 23;
	
	  ;% jc_6_B.Sum3_m
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 27;
	
	  ;% jc_6_B.Sum3_d
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 31;
	
	  ;% jc_6_B.Sum3_p
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (jc_6_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% jc_6_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jc_6_DW.UnitDelay_DSTATE_c
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% jc_6_DW.UnitDelay_DSTATE_k
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 8;
	
	  ;% jc_6_DW.UnitDelay_DSTATE_h
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% jc_6_DW.EncoderInput_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% jc_6_DW.EncoderInput1_PWORK
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% jc_6_DW.AnalogOutput_PWORK
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% jc_6_DW.Scope_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% jc_6_DW.armangle_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% jc_6_DW.fast1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% jc_6_DW.fast2_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% jc_6_DW.r_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% jc_6_DW.rF_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
	  ;% jc_6_DW.slow1_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 9;
	
	  ;% jc_6_DW.slow2_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 10;
	
	  ;% jc_6_DW.u_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1844447724;
  targMap.checksum1 = 3353108918;
  targMap.checksum2 = 2053455349;
  targMap.checksum3 = 3579837393;

