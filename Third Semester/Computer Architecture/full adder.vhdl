library ieee;
use ieee.std_logic_1164.all; 
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity fa1 is
Port ( a,b,ci : in std_logic; 
s,co : out std_logic
); 
end fa1;
architecture Behavioral of fa1 is 
begin
process (a,b,ci)
begin
s<=a xor b xor ci;
co<=(a and b)or (b and ci)or (ci and a);
end process;
end Behavioral;
