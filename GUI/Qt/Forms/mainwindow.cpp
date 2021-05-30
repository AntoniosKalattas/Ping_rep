<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>259</width>
    <height>582</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>MainWindow</string>
  </property>
  <property name="autoFillBackground">
   <bool>true</bool>
  </property>
  <widget class="QWidget" name="centralwidget">
   <property name="styleSheet">
    <string notr="true">background-color:rgb(0, 0, 0)</string>
   </property>
   <layout class="QVBoxLayout" name="verticalLayout">
    <item>
     <widget class="QFrame" name="frame">
      <property name="autoFillBackground">
       <bool>false</bool>
      </property>
      <property name="styleSheet">
       <string notr="true">background-color:rgb(0, 0, 0)</string>
      </property>
      <property name="frameShape">
       <enum>QFrame::StyledPanel</enum>
      </property>
      <property name="frameShadow">
       <enum>QFrame::Raised</enum>
      </property>
      <widget class="QLabel" name="label">
       <property name="geometry">
        <rect>
         <x>40</x>
         <y>80</y>
         <width>133</width>
         <height>16</height>
        </rect>
       </property>
       <property name="autoFillBackground">
        <bool>false</bool>
       </property>
       <property name="styleSheet">
        <string notr="true">color:rgb(255, 255, 255)</string>
       </property>
       <property name="text">
        <string>Write the desire ip address:</string>
       </property>
      </widget>
      <widget class="QPushButton" name="pushButton">
       <property name="geometry">
        <rect>
         <x>60</x>
         <y>150</y>
         <width>80</width>
         <height>21</height>
        </rect>
       </property>
       <property name="styleSheet">
        <string notr="true">color:rgb(255, 255, 255)</string>
       </property>
       <property name="text">
        <string>Start</string>
       </property>
      </widget>
      <widget class="QLabel" name="label_2">
       <property name="geometry">
        <rect>
         <x>20</x>
         <y>230</y>
         <width>191</width>
         <height>131</height>
        </rect>
       </property>
       <property name="font">
        <font>
         <weight>75</weight>
         <bold>true</bold>
        </font>
       </property>
       <property name="styleSheet">
        <string notr="true">background-color:rgb(0, 0, 0);
color:rgb(255, 255, 255)</string>
       </property>
       <property name="text">
        <string/>
       </property>
       <property name="alignment">
        <set>Qt::AlignCenter</set>
       </property>
      </widget>
      <widget class="QLineEdit" name="lineEdit">
       <property name="geometry">
        <rect>
         <x>50</x>
         <y>100</y>
         <width>113</width>
         <height>21</height>
        </rect>
       </property>
       <property name="styleSheet">
        <string notr="true">font-color:rgb(255, 255, 255);
color:rgb(255, 255, 255)</string>
       </property>
      </widget>
     </widget>
    </item>
   </layout>
  </widget>
  <widget class="QMenuBar" name="menubar">
   <property name="geometry">
    <rect>
     <x>0</x>
     <y>0</y>
     <width>259</width>
     <height>20</height>
    </rect>
   </property>
   <widget class="QMenu" name="menuPing_REP">
    <property name="title">
     <string>Ping_REP</string>
    </property>
   </widget>
   <addaction name="menuPing_REP"/>
  </widget>
  <widget class="QStatusBar" name="statusbar"/>
  <widget class="QToolBar" name="toolBar">
   <property name="windowTitle">
    <string>toolBar</string>
   </property>
   <attribute name="toolBarArea">
    <enum>RightToolBarArea</enum>
   </attribute>
   <attribute name="toolBarBreak">
    <bool>false</bool>
   </attribute>
  </widget>
 </widget>
 <resources/>
 <connections/>
</ui>
