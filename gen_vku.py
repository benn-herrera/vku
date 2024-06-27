#!/usr/bin/env python3
import sys
from pathlib import Path
import xml.etree.ElementTree as ET
"""
This is not a user friendly CLI script.
It is intended to be invoked from gen_vku.sh.
Run that instead.
"""

assert len(sys.argv) == 3

VK_XML, VKU_H = Path(sys.argv[1]), Path(sys.argv[2])

assert (VK_XML.name == "vk.xml") and VK_XML.exists() and (VKU_H.name == "vku.h")

tree = ET.parse(VK_XML)
root = tree.getroot()

print(f"{sys.argv[0]}: hooray, we got this far.")
