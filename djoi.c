conf t
interface range fa0/11-17
switchport access vlan 10
interface range fa0/18-24
switchport access vlan 20
interface range fa0/6-10
switchport access vlan 30
copy running-config startup-config
end
copy running-config startup-config