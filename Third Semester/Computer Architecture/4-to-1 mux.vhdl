
library ieee;
use ieee.std_logic_1164.all;
entity Multiplexer is
port(a,b,c,d:in std_logic;
s:in std_logic_vector(1 downto 0);
y:out std_logic);
end Multiplexer;
architecture beh of Multiplexer is
begin
process(a,b,c,d,s)
begin
case s is
when "00"=>y<=a;
when "01"=>y<=b;
when "10"=>y<=c;
when "11"=>y<=d;
when others=>y<='U';
end case;
end process;
end beh;
