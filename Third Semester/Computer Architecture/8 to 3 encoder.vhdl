library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity encod2 is
Port (a: in STD_LOGIC_VECTOR (7 downto 0);
q:out STD_LOGIC_VECTOR (2 downto 0));
end encod2;

architecture Behavioral of encod1 is
begin
q<="000" when a="00000001" else
"001" when a="00000010" else
"010" when a="00000100" else
"011" when a="00001000" else
"100" when a="00010000" else
"101" when a="00100000" else
"110" when a="01000000" else
"111" when a="10000000" else
"XXX";
end Behavioral;
