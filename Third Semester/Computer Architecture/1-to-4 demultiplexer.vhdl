library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity DEMUX is
Port ( I : in STD_LOGIC;
S : in STD_LOGIC_VECTOR (1 downto 0);
Y : out STD_LOGIC_VECTOR (3 downto 0));
end DEMUX;
architecture Behavioral of DEMUX is
begin
process (I, S)
begin
if (S <= "00") then
Y(0) <= I ;
elsif (S <= "01") then
Y(1) <= I ;
elsif (S <= "10") then
Y(2) <= I ;
else
Y(3) <= I ;
end if;
end process;
end Behavioral;
