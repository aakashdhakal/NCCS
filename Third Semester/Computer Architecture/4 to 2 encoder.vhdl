library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity encod1 is
Port (a: in STD_LOGIC_VECTOR (3 downto 0);
q:out STD_LOGIC_VECTOR (1 downto 0));
end encod1;
architecture Behavioral of encod1 is
begin
q<="00" when a="0001" else
"01" when a="0010" else
"10" when a="0100" else
"11" when a="1000" else
"XX";
end Behavioral;
