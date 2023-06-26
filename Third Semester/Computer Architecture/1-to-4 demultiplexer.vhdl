library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity demultiplexer is
Port ( i : in STD_LOGIC;
s0 : in STD_LOGIC;
s1 : in STD_LOGIC;
a : out STD_LOGIC;
b : out STD_LOGIC;
c : out STD_LOGIC;
d : out STD_LOGIC);
end demultiplexer;
architecture Behavioral of demultiplexer is
signal p,q : STD_LOGIC;
begin
p <= not s0;
q <= not s1;
a<= i and p and q;
b<= i and q and s0;
c<= i and p and s1;
d<= i and s1 and s0;
end Behavioral;
